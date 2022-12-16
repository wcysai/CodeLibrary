#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN];
bool match[MAXN];
int d[MAXN];
vector<int> G[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v); G[v].push_back(u);
    d[u]++; d[v]++;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) 
        {
            match[i]=false; G[i].clear(); d[i]=0;
        }
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            add_edge(i,n+a[i]);
            if(a[i]!=b[i]) {add_edge(i,n+b[i]);}
        }
        queue<int> que;
        for(int i=1;i<=2*n;i++) if(d[i]==1) que.push(i);
        while(que.size())
        {
            int v=que.front(); que.pop();
            for(auto to:G[v])
            {
                if(match[to]) continue;
                match[to]=true; match[v]=true; d[v]--; d[to]--;
                for(auto tto:G[to])
                {
                    d[tto]--;
                    if(d[tto]==1) que.push(tto); 
                }
                break;
            }
        }
        bool f=true;
        for(int i=1;i<=2*n;i++) if(!match[i]&&!d[i]) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

