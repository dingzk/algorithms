#ifndef TRIE_H__
#define TRIE_H__
#define MAX 257
#define MAX_TRIE_WORD_LEN 200
#define MARK_TAG_OPEN "<em class=\"s-color-red\">"
#define MARK_TAG_OPEN_LEN 24
#define MARK_TAG_CLOSE "</em>"
#define MARK_TAG_CLOSE_LEN 5

#define COPY_AND_EXPAND(dst, src, len) do { \
    strncpy(dst, src, len);\
    dst += len;\
} while(0);

typedef struct trie {
    uint8_t key;
    int is_leaf;
    struct trie *next[MAX];
} Trie;

Trie *root;


Trie *create(uint8_t key, int is_leaf);
void insert(char *str);
int match(const char *str, char *matched);
int match_all(const char *str, char *str_marked);
void free_trie(Trie *trie);

#endif
