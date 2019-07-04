#include<bits/stdc++.h>
#define MAXN 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,m,r,sz;
db dp[(1<<12)][11][27];
bool vis[(1<<12)][11][27];
string str;
db q[11];
vector<char> v;
int cnt[12];
db prob(int pos,int i,int j,int k)
{
    db x=pow(q[pos],1.0/(k-j+1));
    db y=(i==j?1:pow(1-1.0/i,i-j));
    return (1-x)*j/i+x*y;
}
db solve(int mask,int pos,int i,int j,int k)
{
    if(mask==(1<<sz)-1) return (pos==r?1.0:0.0);
    if(vis[mask][pos][i]) return dp[mask][pos][i];
    if(i<j) return 0;
    db &res=dp[mask][pos][i];
    db p=prob(pos,i,j,k);
    res=solve(mask,pos%n+1,i-1,j,k)*(1-p);
    for(int tot=0;tot<sz;tot++) if(!(mask&(1<<tot))) res+=solve(mask^(1<<tot),pos,i-1,j-1,k-cnt[tot])*p/j;
    vis[mask][pos][i]=true;
    return res;
}
int main()
{
    freopen("wheel.in","r",stdin);
    freopen("wheel.out","w",stdout);
    scanf("%d%d",&n,&r);
    cin>>str;
    m=(int)str.size();
    for(int i=0;i<m;i++) v.push_back(str[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    sz=(int)v.size();
    for(int i=0;i<m;i++)
    {
        int id=lower_bound(v.begin(),v.end(),str[i])-v.begin();
        cnt[id]++;
    }
    for(int i=1;i<=n;i++) scanf("%Lf",&q[i]);
    memset(vis,false,sizeof(vis));
    printf("%.10Lf\n",solve(0,1,26,sz,m));
    return 0;
}
