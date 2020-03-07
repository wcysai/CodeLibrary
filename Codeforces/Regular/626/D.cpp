#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,l[MAXN],s[MAXN],c[MAXN];

int dp[MAXN][MAXN],ndp[MAXN][MAXN];
bool has[MAXN][MAXN];

vector<P> states;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void upd(int x,int y,int z)
{
    ndp[x][y]=max(ndp[x][y],z);
    if(!has[x][y])
    {
        has[x][y]=true;
        states.push_back(P(x,y));
    }
}
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
P calc(int x,int y,int z)
{
    if(x==z) return P(0,y);
    if(y==1) return P(0,0);
    P p=calc(x+1,y/2,z);
    p.F+=c[x+1]*(y/2);
    return p;
}
int main()
{
    memset(has,false,sizeof(has));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&l[i]);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=1;i<=n+m;i++) scanf("%d",&c[i]);
    states.push_back(P(0,0));
    has[0][0]=true;
    for(int i=n;i>=1;i--)
    {
        for(auto p:states) ndp[p.F][p.S]=-INF;
        for(auto p:states)
        {
            int x=p.F,y=p.S;
            ndp[x][y]=dp[x][y];
            if(x>l[i]) continue;
            P pp=calc(x,y,l[i]);
            upd(l[i],pp.S+1,dp[x][y]-s[i]+c[l[i]]+pp.F);
        }
        for(auto p:states) dp[p.F][p.S]=ndp[p.F][p.S];
    }
    int ans=0;
    for(auto p:states)
    {
        int x=p.F,y=p.S;
        ans=max(ans,dp[x][y]+calc(x,y,6000).F);
    }
    printf("%d\n",ans);
    return 0;
}