#include<bits/stdc++.h>
#define MAXN 250005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
vector<int> v;
ll solve(int d,vector<int> &v)
{
    if(v.size()<2) return 0;
    static int cnta[4][18],cntb[4][18];
    if(d==-1) 
    {
        ll ans=0;
        memset(cnta[0],0,sizeof(cnta[0]));
        for(auto x:v)
            for(int j=0;j<=17;j++)
                if(a[x]&(1<<j)) cnta[0][j]++;
        for(int j=0;j<=17;j++) ans+=(1LL<<j)*(cnta[0][j])*((int)v.size()-cnta[0][j]);
        return ans;
    }
    vector<int> v0,v1;
    for(auto x:v)
    {
        int p=(a[x]>>d)&1,q=(b[x]>>d)&1;
        if(p^q) v1.push_back(x); else v0.push_back(x);
    }
    ll ans=0;
    ans+=solve(d-1,v0); ans+=solve(d-1,v1);
    
    memset(cnta,0,sizeof(cnta)); memset(cntb,0,sizeof(cntb));
    vector<int> vv[4];
    for(int i=0;i<4;i++) vv[i].clear();
    for(auto x:v)
    {
        int p=(a[x]>>d)&1,q=(b[x]>>d)&1;
        vv[p*2+q].push_back(x);
    }
    for(int i=0;i<4;i++)
    {
        for(auto x:vv[i])
        {
            for(int j=0;j<=17;j++)
            {
                if(a[x]&(1<<j)) cnta[i][j]++;
                if(b[x]&(1<<j)) cntb[i][j]++;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            int p=((i>>1)&1)^((j>>1)&1),q=(i&1)^(j&1);
            if(p==q) continue;
            for(int k=0;k<=17;k++)
            {
                if(p<q)//credit goes to A 
                {
                    ans+=(1LL<<k)*(cnta[i][k])*((int)vv[j].size()-cnta[j][k]);
                    ans+=(1LL<<k)*(cnta[j][k])*((int)vv[i].size()-cnta[i][k]);
                }
                else//credit goes to B
                {
                    ans+=(1LL<<k)*(cntb[i][k])*((int)vv[j].size()-cntb[j][k]);
                    ans+=(1LL<<k)*(cntb[j][k])*((int)vv[i].size()-cntb[i][k]);
                }
            }
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) v.push_back(i);
    printf("%lld\n",solve(17,v));
}