//【快排方案】
//枢纽为数组最左边数
//头尾指针相互比较直至相遇

#include <iostream>
using namespace std;

const int N = 1e5;

int n, q[N];
void quickSort(int q[], int l, int r);

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    quickSort(q, 0, n-1);
    for (int i = 0; i < n; ++i) printf("%d ", q[i]);
    return 0;
}

void quickSort(int q[], int l, int r)
{
    if (l>=r)   return;
    int x = q[l], i = l - 1, j = r + 1;
    while (i < j) 
    {
        do ++i; while(q[i] < x);
        do --j; while(q[j] > x);
        if (i < j)  swap(q[i], q[j]);
    }
    
    //分治
    quickSort(q, l, j);
    quickSort(q, j+1, r);
}
