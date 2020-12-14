#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010, S = 55, M = 1000010;

int n;
int tr[N * S][26], cnt[N * S], idx;
char str[M];
int q[N * S], ne[N * S];

void insert()
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int t = str[i] - 'a';
        if (!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
    }
    cnt[p] ++ ;
}

void build()
{
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i ++ )
        if (tr[0][i])
            q[ ++ tt] = tr[0][i];

    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = 0; i < 26; i ++ )
        {
            int p = tr[t][i];
            /*
            一层一层的更新过来维护每个节点的最近的可匹配前缀编号, 由一个一个的跳, 变成了一步到胃, t的儿子都没有i, 
            那匹配的儿子里面的i必然是匹配不到了.
            空的还是要赋起走tr[t][i] = tr[ne[t]][i], 以便后面的不空的用tr[ne[t]][i]赋值
            */
            if (!p) tr[t][i] = tr[ne[t]][i]; // 这样就形成了一个链式关系, 当前节点的最大前缀一定是由前面的转移过来的 ****
            else
            {
                ne[p] = tr[ne[t]][i]; // 可能j(ne[t])指针的儿子节点中, 没有i, **但是tr[ne[t]][i]的值为离他最近的最大前缀坐标.****过滤掉了ne的子节点也没有i这个儿子节点的情况.**
                q[ ++ tt] = p;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(ne, 0, sizeof ne);
        idx = 0;

        scanf("%d", &n);
        for (int i = 0; i < n; i ++ )
        {
            scanf("%s", str);
            insert();
        }

        build();

        scanf("%s", str);

        // 时间复杂度 O(55 * 1e6) 稳55 * 1e6
        int res = 0;
        for (int i = 0, j = 0; str[i]; i ++ )
        {
            int t = str[i] - 'a';
            j = tr[j][t]; // 将原来需要跳多次, 通过维护最大前缀坐标, 就可以一次性跳转.

            int p = j;
            while (p) // 最多55次循环, 可忽略不计
            {
                res += cnt[p];
                cnt[p] = 0;
                p = ne[p];
            }
        }

        printf("%d\n", res);
    }

    return 0;
}

