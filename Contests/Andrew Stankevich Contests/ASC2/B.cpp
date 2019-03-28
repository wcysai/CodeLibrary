#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 66
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
ll dp[MAXN][MAXN],choice[MAXN][MAXN];
vector<int> st[MAXN];
void go(int s,int e)
{
    if(st[e].size()==0) printf("move %d from %d to %d\n",st[s].back(),s,e);
    else printf("move %d from %d to %d atop %d\n",st[s].back(),s,e,st[e].back());
    st[e].push_back(st[s].back()); st[s].pop_back(); 
}
void solve(int s,int e,int disk,int peg)
{
    if(disk==1)
    {
        go(s,e); return;
    }
    int k=choice[disk][peg];
    int id=-1;
    for(int i=1;i<=m;i++)  if((!st[i].size()||st[i].back()>st[s].back())&&i!=e) {id=i; break;}
    solve(s,id,k,peg);
    solve(s,e,disk-k,peg-1);
    solve(id,e,k,peg);
}
int main()
{
    freopen("hanoi.in","r",stdin);
    freopen("hanoi.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(i==1) dp[i][j]=1;
            else if(j<=2) dp[i][j]=INF;
            else
            {
                dp[i][j]=INF;
                for(int k=1;k<=i-1;k++) 
                {
                    if(2LL*dp[k][j]+dp[i-k][j-1]<dp[i][j])
                    {
                        dp[i][j]=2LL*dp[k][j]+dp[i-k][j-1];
                        choice[i][j]=k;
                    }
                }
            }
        }
    }
    printf("%lld\n",dp[n][m]);
    for(int i=1;i<=n;i++) st[1].push_back(i);
    reverse(st[1].begin(),st[1].end());
    solve(1,m,n,m);
    return 0;
}

