#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(ll &a,ll b) {a+=b;}
int n;
ll ans;
vector<int> part;
bool check()
{
    int blackcnt=0,whitecnt=0;
    for(int i=0;i<(int)part.size();i++)
    {
        blackcnt+=(i&1?part[i]/2:(part[i]+1)/2);
        whitecnt+=(i&1?(part[i]+1)/2:(part[i]/2));
    }
    if(blackcnt==0&&whitecnt==0) return true;
    if(!(blackcnt==whitecnt+1||blackcnt==whitecnt)) return false;
    int need=blackcnt-whitecnt;
    for(int i=0;i<(int)part.size();i++)
    {
        if(!part[i]) continue;
        if(i<(int)part.size()-1&&part[i]==part[i+1]) continue;
        if(((i+part[i])&1)!=need) continue;
        part[i]--;
        bool f=check();
        part[i]++;
        if(f) return true;
    }
    return false;
}
void dfs(int rem,int maxi)
{
    if(rem==0)
    {
        if(check()) ans++;
        return;
    }
    for(int i=1;i<=min(rem,maxi);i++)
    {
        part.push_back(i);
        dfs(rem-i,i);
        part.pop_back();
    }
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    scanf("%d",&n);
    ans=0;
    dfs(n,n);
    printf("%lld\n",ans);
    return 0;
}
