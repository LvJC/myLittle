/*
POJ 2524
给m对关系，每队关系表示两人信仰同一个宗教，共n个人。问n个人最多信仰多少个宗教？
输入案例：
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

输出案例：
Case 1: 1
Case 2: 7
*/

#include <iostream>
using namespace std;

const int N = 100010;
int fa[N];

int find(int x)
{
    while(x!=fa[x])
        x = fa[x];
    return x;
}

void merge(int k1, int k2)
{
    int f1 = find(k1), f2 = find(k2);
    if (f1!=f2)
        fa[f1] = f2;
    
    return;
}



int main()
{
    int n, m, Case = 0;
    while(~scanf("%d%d", &n, &m))
    {
        if (0==n)   continue;
        //init
        for (int i = 1; i <= n; ++ i)
        {
            fa[i] = i;
        }
        //merge
        for (int i = 1; i <= m; ++ i)
        {
            int k1, k2;
            scanf("%d%d", &k1, &k2);
            merge(k1, k2);
        }
        //find and count
        int cnt = 0;
        for (int i = 1; i <= n; ++ i)
        {
            if (find(i)==i)
            {
                cnt ++;
            }
        }
        
        printf("Case %d: %d\n", ++Case, cnt);
        
    }

    return 0;
}
