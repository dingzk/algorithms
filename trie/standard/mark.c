#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "trie.h"

#define DEBUG

inline Trie *create(uint8_t key, int is_leaf)
{
    Trie *node = (Trie *)malloc(sizeof(Trie));    
    node->key = key;
    node->is_leaf = is_leaf;
    memset(node->next, 0, sizeof(MAX * sizeof(Trie *)));

    return node;
}

void insert(char *str)
{
    Trie *cur = root;
    int is_leaf = 0;
    char key;
    int i; 
    unsigned int offset;
    size_t len = strlen(str);
    for (i = 0; i <= len; i++) {
        if (i == len) {
            is_leaf = 1;
            key = '$';
            offset = MAX-1;
        } else {
            key = str[i];
            if (isalpha(key)) {
                key = tolower(key);
            }
            offset = (uint8_t)key;
        }
        if (cur->next[offset] == NULL) {
            cur->next[offset] = create((uint8_t)key, is_leaf); 
        }
        cur = cur->next[offset];
    }
}

int match(const char *str, char *matched)
{
    Trie *cur = root;
    size_t len = strlen(str);
    int i; 
    unsigned int offset = 0;
    char key;
    for (i = 0; i < len; i++) {
        key = *(str + i);
        if (isalpha(key) && isupper(key)) {
            key = tolower(key);
        }
        offset = (uint8_t) key;
        if (cur->next[offset] == NULL) {
            return 0;
        }
        matched[i] = *(str + i);
        cur = cur->next[offset];
        if (cur->next[MAX-1] != NULL) {
            return 1;
        }
    }

    return -1;
}

char *match_all(const char *str)
{
    size_t str_len = strlen(str), matched_len = 0;
    if (str_len <= 0) {
        return NULL;
    }
    char matched[MAX] = {0};
    char *str_marked = calloc(MAX_MARKED, sizeof(char));
    char *marked = str_marked;
    int i = 0;
    while (i < str_len) {
        if (match(str + i, matched)) {
            matched_len = strlen(matched); 
            printf("matched:%s\n", matched);
            COPY_AND_EXPAND(marked, MARK_TAG_OPEN, MARK_TAG_OPEN_LEN)
            COPY_AND_EXPAND(marked, str + i, matched_len)
            COPY_AND_EXPAND(marked, MARK_TAG_CLOSE, MARK_TAG_CLOSE_LEN)
            i += matched_len;
            memset(matched, 0, sizeof(char) * MAX);
        } else {
            *marked++ = str[i++];
        }
    }

    return str_marked;
}

void free_trie(Trie *cur)
{
    if (cur == NULL) {
        return;    
    }
    //printf("%c\n", cur->key);
    if (!cur->is_leaf) {
        Trie **next = cur->next;
        int i;
        for (i = 0; i < MAX; i++) {
            free_trie(*next++);
        }
    }
    free(cur);
}

Token *create_token(size_t off_start, size_t off_end, bool is_tag, const char *str) 
{
    size_t len, copylen;
    if (off_end < off_start) {
        return NULL;
    }
    copylen = off_end - off_start + 1;
    Token *node = malloc(sizeof(Token) + copylen);
    node->is_tag = is_tag;
    strncpy(node->str, str + off_start, copylen);
    *(node->str + copylen) = '\0';
    node->next = NULL;

    return node;
}

Token *token_get_all(const char *str)
{
    size_t str_len = strlen(str);
    int off_start = 0, off_end = 0; 
    Token *root = create_token(0, 0, 0, str);
    Token *node, *curnode = root;
    bool flag = false, is_tag;
    int i;
    for (i = 0; i < str_len; i++) {
        off_end = i;
        if (off_end == str_len - 1) {
            flag = true;
            is_tag = 0;
        }
        if (str[i] == '<' && i != 0) {
            flag = true;
            is_tag = 0;
            off_end -= 1;
        } else if (str[i] == '>') {
            flag = true;
            is_tag = 1;
        }
        if (flag) {
            //printf("%d, %d, %d\n", off_start, off_end, is_tag);
            node = create_token(off_start, off_end, is_tag, str);
            if (node != NULL) {
                curnode->next = node;
                curnode = node;
            }
            flag = false;
            off_start = off_end + 1;
        }
    }

    return root;
}

int free_token_all(Token *root, char *dst)
{
    if (root == NULL) {
        return 1;
    } 
    Token *cur = root->next;
    Token *tmp;
    char *target;
    bool is_tag;
    char *mark;
    while (cur != NULL) {
        //printf("str: %s, is_tag : %d\n", cur->str, cur->is_tag);
        target = cur->str;
        is_tag = cur->is_tag;
        if (!is_tag) {
            mark = match_all(target);
            strcat(dst, mark);
            free(mark);
        } else {
            strcat(dst, target);
        }
        tmp = cur->next;
        free(cur);
        cur = tmp;
    } 

    return 0;
}

#ifdef DEBUG
int main(void)
{
    extern Trie *root;
    root = create('`', 0);
    
    insert("部队烧烤壮行宴");
    insert("部队");
    insert("烧烤");
    insert("壮行");
    insert("宴");
    insert("部隊");
    insert("燒烤");
    insert("壯行");
    insert("宴");
    char dst[2048] = {0};
    char *target = "【部队烧烤“壮行宴”了解一下<img src=\"//img.t.sinajs.cn/t4/appstyle/expression/ext/normal/fa/2018new_chanzui_org.png\" title=\"[馋嘴]\" alt=\"[馋嘴]\" class=\"face\" /><img src=\"//img.t.sinajs.cn/t4/appstyle/expression/ext/normal/fa/2018new_chanzui_org.png\" title=\"[馋嘴]\" alt=\"[馋嘴]\" class=\"face\" />】6月9日，正值周末，中部战区空军地导某营官兵齐聚篮球场，一场别开生面的烧烤晚会即将拉开序幕。在该营即将接换新装、赴华北某地执行任务之际，为让大家在紧张训练之余更好放松身心，这顿广大官兵期盼已久的集体“壮行宴”应运而生。（杨杰 任俊吉 谭巳成 ";

    Token *t = token_get_all(target);
    free_token_all(t, dst);
    printf("%s\n", dst);

    /*
    char *mark = match_all(target);
    printf("%s\n", mark);
    free(mark);
    */
    free_trie(root);

    return 0;
}
#endif
