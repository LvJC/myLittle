//归并是先分后排，归并的分界点在定义域（下标）上
//快排是先排后分,快排的分界点在值域上
#include <iostream>
using namespace std;

const int N = 1e5;
int n, q[N], tmp[N];

void mergeSort(int q[], int l, int r){
    if (l==r)   return;
    
    int mid = l + r >> 1;
    //先分
    mergeSort(q, l, mid);   mergeSort(q, mid+1, r);
    //再合
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if (q[i]<=q[j]) tmp[k++] = q[i++];
        else            tmp[k++] = q[j++];
    }
    //第一组还有数
    while(i <= mid)     tmp[k++] = q[i++];
    //第二组还有数
    while(j <= r)       tmp[k++] = q[j++];
    //tmp换回q
    //i指向q[] j指向tmp[]
    for(i=l, j=0; i<=r; ++i, ++j)   q[i] = tmp[j];
}


int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i)    scanf("%d", &q[i]);
    mergeSort(q, 0, n-1);
    for (int i = 0; i < n; ++ i)    printf("%d ", q[i]);
    
    return 0;
}
