#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN];
int fact[MAXN];
int fa[MAXN],cntv[MAXN],cnte[MAXN],r[MAXN],ans;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        cntv[i]=1;
        cnte[i]=0;
        r[i]=0;
    }
}
int find(int x)
{
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) {cnte[x]++; return;}
    if(r[x]<r[y]) 
    {
        fa[x]=y;
        cntv[y]+=cntv[x];
        cnte[y]+=cnte[x]+1;
    }
    else
    {
        fa[y]=x;
        cntv[x]+=cntv[y];
        cnte[x]+=cnte[y]+1;
        if(r[x]==r[y]) r[x]++;
    }
}
int dp[MAXN],ndp[MAXN];
vector<int> sz;
int main()
{
    fact[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&n);
    int k=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        if(p[i]==-1) k++;
    }
    ans=1LL*n*pow_mod(n-1,k)%MOD;
    init(n);
    for(int i=1;i<=n;i++) if(p[i]!=-1) unite(i,p[i]);
    for(int i=1;i<=n;i++)
    {
        if(i==find(i))
        {
            if(cntv[i]==cnte[i]) dec(ans,pow_mod(n-1,k));
            else sz.push_back(cntv[i]);
        }
    }
    dp[0]=1;
    for(int i=0;i<(int)sz.size();i++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<=i;j++)
        {
            add(ndp[j],dp[j]);
            add(ndp[j+1],1LL*dp[j]*sz[i]%MOD);
        }
        swap(dp,ndp);
    }
    for(int i=2;i<=(int)sz.size();i++)
    {
        dec(ans,1LL*dp[i]*fact[i-1]%MOD*pow_mod(n-1,k-i)%MOD);
    }
    for(int i=0;i<k;i++)
    {
        dec(ans,1LL*(sz[i]-1)*pow_mod(n-1,k-1)%MOD);
    }
    printf("%d\n",ans);
}
