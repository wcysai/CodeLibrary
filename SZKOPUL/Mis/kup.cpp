#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,k,a[MAXN][MAXN];
int down[MAXN][MAXN];
ll sum[MAXN][MAXN];
int L[MAXN],R[MAXN],st[MAXN],t;
ll get_sum(int l,int r,int u,int d)
{
    return sum[d][r]-sum[u-1][r]-sum[d][l-1]+sum[u-1][l-1];
}
void solve(int l,int r,int u,int d,ll s)
{
    if(s>=k&&s<=2*k)
    {
        printf("%d %d %d %d\n",l,u,r,d);
        exit(0);
    }
    if(l<r)
    {
        int mid=(l+r)/2;
        ll s2=get_sum(l,mid,u,d);
        if(s2>=k) solve(l,mid,u,d,s2); else solve(mid+1,r,u,d,s-s2);
        return;
    }
    else
    {
        int mid=(u+d)/2;
        ll s2=get_sum(l,r,u,mid);
        if(s2>=k) solve(l,r,u,mid,s2); else solve(l,r,mid+1,d,s-s2);
        return;
    }
}
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]>2*k) down[i][j]=-1;
            else if(i==n) down[i][j]=i;
            else down[i][j]=(down[i+1][j]==-1?i:down[i+1][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        t=0;
        for(int j=1;j<=n;j++)
	    {
		    while(t>0&&down[i][st[t-1]]>=down[i][j]) t--;
		    L[j]=(t==0?0:st[t-1]);
		    st[t++]=j;
	    }
	    t=0;
	    for(int j=n;j>=1;j--)
	    {
		    while(t>0&&down[i][st[t-1]]>=down[i][j]) t--;
		    R[j]=(t==0?n+1:st[t-1]);
		    st[t++]=j;
	    }
        for(int j=1;j<=n;j++)
        {
            if(down[i][j]==-1) continue;
            int l=L[j]+1,r=R[j]-1,u=i,d=down[i][j];
            ll s=get_sum(l,r,u,d);
            if(s>=k) solve(l,r,u,d,s); 
        }
    }
    puts("NIE");
    return 0;
}
