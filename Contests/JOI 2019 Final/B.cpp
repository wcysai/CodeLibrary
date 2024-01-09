#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int c[MAXN];
P v[MAXN];
int vv[MAXN];
int mini[MAXN];
P dp[MAXN];
int st[MAXN][20];
int pre[MAXN];
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n-1;i>=0;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<n;++j)
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int get_next(int pos,int val)
{
    int l=pos,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(query(pos+1,mid)<=val) r=mid; else l=mid;
    }
    return r;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[i]=P(y,x);
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    sort(c+1,c+m+1);
    int ans=0,cur=m;
    for(int i=n;i>=1;i--)
        if(cur>=1&&c[cur]>=v[i].S) ans++,cur--;
    printf("%d\n",ans);
}
