#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m;
int paint[MAXN],cnt[MAXN],l[MAXN],r[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        paint[l[i]]++;
        paint[r[i]+1]--;
    }
    for(int i=1;i<=n;i++)
        paint[i]+=paint[i-1];
    int res=0;
    cnt[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(paint[i]==1) cnt[i]=cnt[i-1]+1; else cnt[i]=cnt[i-1];
        if(paint[i]==0) res++;
    }
    for(int i=0;i<m;i++)
        printf("%d\n",res+cnt[r[i]]-cnt[l[i]-1]);
    return 0;
}

