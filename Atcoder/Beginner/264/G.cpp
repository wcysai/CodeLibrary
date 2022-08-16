#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXC 30
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
struct aho_corasick 
{
    int cnt=0,kmp[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    long long dp[MAXN],dist[MAXN];
 
    void add(string &s,int c) 
    {
        int cur=0;
        for(char &c:s) 
        {
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        dp[cur]+=c;
    }
 
    void BFS() 
    {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) 
        {
            int u=q.front();
            dp[u]+=dp[kmp[u]];
            for(int i=0;i<MAXC;i++) 
            {
                if(ch[u][i]>0) 
                {
                    int v=ch[u][i];
                    q.push(v);
                    nxt[u][i]=v;
                    kmp[v]=nxt[kmp[u]][i];
                    if (kmp[v]==v) kmp[v]=0;
                } 
                else nxt[u][i]=nxt[kmp[u]][i];
            }
        }
    }
    ll solve()
    {
        for(int i=0;i<=cnt;i++) dist[i]=-INF;
        for(int k=0;k<26;k++) dist[nxt[0][k]]=dp[nxt[0][k]];
        bool upd;
        for(int i=0;i<500;i++)
        {
            upd=false;
            for(int j=0;j<=cnt;j++)
            {
                if(dist[j]==-INF) continue;
                for(int k=0;k<26;k++)
                {
                    int to=nxt[j][k];
                    if(dist[to]<dist[j]+dp[to])
                    {
                        dist[to]=dist[j]+dp[to];
                        upd=true;
                    }
                }
            }
            if(!upd) break;
        }
        if(upd) return -INF;
        ll ans=-INF;
        for(int j=0;j<=cnt;j++) ans=max(ans,dist[j]);
        return ans;
    }
} acs;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        int cost;
        cin>>str>>cost;
        acs.add(str,cost);
    }
    acs.BFS();
    ll ans=acs.solve();
    if(ans==-INF) cout<<"Infinity"<<endl; else cout<<ans<<endl;
    return 0;
}

