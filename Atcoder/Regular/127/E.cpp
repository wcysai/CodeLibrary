#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dp[MAXN][MAXN];
int a,b,x[MAXN];
vector<int> pos[2];
int match[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
set<int> v;
//dp[l][r] deleted l pairs of (1,2) from the beginning
//then r 1s from the end
//deleted 2s: l from the end
//deleted 1s: l+r from the end
int solve(int l,int r)
{
    if(dp[l][r]!=-1) return dp[l][r];
    if(l==b) return 1;
    int p=match[pos[1][b-1-l]];
    dp[l][r]=0;
    if(pos[0][a-1-(l+r)]>p)//last is one, maximum can be preserved
    add(dp[l][r],solve(l,r+1));
    //maximum erased
    add(dp[l][r],solve(l+1,r));
    return dp[l][r];
}
int main()
{
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a+b;i++) scanf("%d",&x[i]);
    for(int i=1;i<=a+b;i++) pos[x[i]-1].push_back(i);
    for(int i=1;i<=a+b;i++)
        if(x[i]==1)
            v.insert(i);
    for(int i=a+b;i>=1;i--)
    {
        if(x[i]==2)
        {
            auto it=v.upper_bound(i);
            it--;
            match[i]=*it;
            v.erase(it);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(0,0));
    return 0;
}