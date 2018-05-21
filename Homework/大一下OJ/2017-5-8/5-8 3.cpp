#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 3000005
using namespace std;
int parent(int i)
{
    return (i/2);
}
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
typedef struct
{
    int key,ind;
}node;
node heap[MAXN];
int n,k;
int l[MAXN],r[MAXN],t[MAXN];
int num[MAXN];
void swap(int x,int y)
{
    node p=heap[x];
    heap[x]=heap[y];
    heap[y]=p;
}
void min_heapify(int i)
{
    int L=left(i);
    int R=right(i);
    int smallest;
    if(L<=k&&heap[L].key<heap[i].key)
        smallest=L;
    else smallest=i;
    if(R<=k&&heap[R].key<heap[smallest].key)
        smallest=R;
    if(smallest!=i)
    {
        swap(i,smallest);
        min_heapify(smallest);
    }
    return;
}
int main()
{
    n=1;
    k=1,l[1]=1,t[1]=1;
    while(scanf("%d",&num[n])==1)
            n++;
    n--;
    for(int i=2;i<=n;i++)
    {
        if(num[i-1]>num[i])
        {
            r[k]=i-1;
            k++;
            l[k]=i;
            t[k]=i;
        }
        r[k]=n;
    }
    for(int i=1;i<=k;i++)
    {
        heap[i].key=num[l[i]];
        heap[i].ind=i;
    }
    for(int i=k/2;i>=1;i--)
        min_heapify(i);
    for (int i=1;i<=n;i++)
        {
        printf("%d", heap[1].key);
        if (i!=n) printf(" ");    else { printf("\n"); break; };

        int j=heap[1].ind;
        if (t[j]!=r[j]) {
            t[j]++; heap[1].key = num[t[j]];
        }
        else {
            heap[1] = heap[k];
            k--;
        }
        min_heapify(1);
    }

    return 0;
}
