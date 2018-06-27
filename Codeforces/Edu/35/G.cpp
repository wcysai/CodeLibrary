#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
const int block=400;
int n,q;
int a[MAXN];
int save[MAXN/block+1][101];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<(n-1)/block+1;i++)
        for(int j=1;j<=100;j++)
            save[i][j]=j;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r,x,y;
        scanf("%d%d%d%d",&l,&r,&x,&y);
        l--;r--;
        int lb=(l-1)/block+1,rb=(r-1)/block+1;
        if(lb==rb)
        {
            for(int j=l;j<=r;j++)
            {
                int x=a[j]
            }
        }
    }
}
