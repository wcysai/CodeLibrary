#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str;
int type[MAXN],cnta[MAXN],cntb[MAXN];
vector<int> G[MAXN];
bool deleted[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    cin>>str;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='A') type[i+1]=0; else type[i+1]=1;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
        if(type[v]) cntb[u]++; else cnta[u]++;
        if(u!=v)
        {
            if(type[u]) cntb[v]++; else cnta[v]++;
        }
    }
    int ans=0;
    memset(deleted,false,sizeof(deleted));
    queue<int> que;
    for(int i=1;i<=n;i++)
    {
        if(!cnta[i]||!cntb[i])
        {
            deleted[i]=true;
            que.push(i);
            ans++;
        }
    }
    while(que.size())
    {
        int v=que.front();que.pop();
        for(auto to:G[v])
        {
            if(deleted[to]) continue;
            if(type[v]) cntb[to]--; else cnta[to]--;
            if(!cnta[to]||!cntb[to])
            {
                ans++;
                deleted[to]=true;
                que.push(to);
            }
        }
    }
    if(ans==n) puts("No"); else puts("Yes");
    return 0;
}

