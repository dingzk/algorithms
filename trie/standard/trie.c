#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"

//#define DEBUG

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

int match_all(const char *str, char *str_marked)
{
    size_t str_len = strlen(str), matched_len = 0;
    if (str_len <= 0) {
        return -1;
    }
    char matched[MAX_TRIE_WORD_LEN] = {0};
    char *marked = str_marked;
    int i = 0;
    while (i < str_len) {
        if (match(str + i, matched) == 1) {
            matched_len = strlen(matched); 
            //printf("matched:%s\n", matched);
            COPY_AND_EXPAND(marked, MARK_TAG_OPEN, MARK_TAG_OPEN_LEN)
            COPY_AND_EXPAND(marked, str + i, matched_len)
            COPY_AND_EXPAND(marked, MARK_TAG_CLOSE, MARK_TAG_CLOSE_LEN)
            i += matched_len;
            memset(matched, 0, sizeof(char) * MAX_TRIE_WORD_LEN);
        } else {
            *marked++ = str[i++];
        }
    }

    return 0;
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
    char *target = "部队烧烤壮行晏abcdsjdjfjsdfoiajo";

    char marked[10240] = {0};
    match_all(target, marked);
    printf("%s\n", marked);
    free_trie(root);

    return 0;
}
#endif
