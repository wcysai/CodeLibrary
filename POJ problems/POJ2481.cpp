#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 100000
using namespace std;
int bit[MAXN+1];
struct cow
{
    int left,right,ord;
} a[MAXN];
int save[MAXN];
bool cmp(const cow &x,const cow &y)
{
    if(x.right==y.right) return x.left<y.left;
    return x.right > y.right;
}
int sum(int x)
{
    int s=0;
    for(int i=x;i>0;i-=i&-i)
        s+=bit[i];
    return s;
}
void add(int x,int d)
{
    for(int i=x;i<=MAXN;i+=i&-i)
        bit[i]+=d;
}
int n;
int main()
{
    scanf("%d",&n);
    while(n!=0)
    {
    memset(save,0,sizeof(save));
    memset(bit,0,sizeof(bit));
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].left,&a[i].right);
        a[i].left++;
        a[i].right++;
        a[i].ord=i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(a[i].left==a[i-1].left&&a[i].right==a[i-1].right) save[a[i].ord]=save[a[i-1].ord];
        else save[a[i].ord]=sum(a[i].left);
        add(a[i].left,1);
    }
       for(int i=0;i<n-1;i++)
    {
        printf("%d ",save[i]);
    }
    printf("%d\n",save[n-1]);
    scanf("%d",&n);
    }
    return 0;
}
