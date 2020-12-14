#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

const int N = 10010, M = 1000010;

int tr[55 * N][26], cnt[55 * N], idx; // cnt维护以某个点结尾的单词数量
int q[55 * N], ne[55 * N]; // AC自动机 ne对于trie树中的每个节点都要维护这么个值
char str[M];

void insert ()
{
    int p = 0;
    for(int i = 0 ; str[i] ; i ++ )
    {
        int t = str[i] - 'a';
        if(!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
    }
    cnt[p] ++ ;
}

void build ()
{
    int hh = 0, tt = -1;
    for(int i = 0 ; i < 26 ; i ++ )
        if(tr[0][i])
            q[++ tt] = tr[0][i];

    while(hh <= tt)
    {
        int t = q[hh ++ ];
        for(int i = 0 ; i < 26 ; i ++ )
        {
            int p = tr[t][i];
            int j = ne[t];
            if(!tr[t][i]) continue;

            while(j && !tr[j][i]) j = ne[j];
            if(tr[j][i]) j = tr[j][i];
            ne[p] = j;
            q[++ tt] = p;
        }
    }
}

int main ()
{
    int T;
    cin >> T;
    while(T -- )
    {
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(ne, 0, sizeof ne);
        idx = 0;

        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i ++ ) 
        {
            scanf("%s", str); // 读入字符串的时候, 每次都会更新\0的位置, 因此无需清空字符数组的
            insert();
        }

        build();

        scanf("%s", str);
        int res = 0;

        // 时间复杂度: 1e6 * 55 我们可以发现while循环的时间复杂度取决于树的最大深度 但是其常数可能比比建trie图的大一些  可忽略不计
        for(int i = 0, j = 0 ; str[i] ; i ++ )
        {
            int t = str[i] - 'a';
            while(j && !tr[j][t]) j = ne[j];
            if(tr[j][t]) j = tr[j][t];

            /*
            还需要加上该串的最大后缀(相当于是前缀, 这个后缀是由更小的后缀转移过来的)
            如果该前缀是单词, 那么ne[p]是尾节点编号, cnt[ne[p]] > 0, 加上就行, 不是单词+0, 就相当于没加.
            */
            int p = j;
            while(p) // 最长55次循环
            {
                res += cnt[p];
                cnt[p] = 0; // 加了就清空防止重复
                p = ne[p];
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

