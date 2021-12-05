#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,l[MAXN],r[MAXN];
vector<P> G[MAXN];
int d[MAXN];
void bfs()
{
    for(int i=0;i<=n;i++) d[i]=INF;
    d[0]=0;
    deque<int> que;
    que.push_back(0);
    while(que.size())
    {
        int v=que.front(); que.pop_front();
        for(auto p:G[v])
        {
            int to=p.F,cost=p.S;
            if(d[to]==INF)
            {
                d[to]=d[v]+cost;
                if(cost==0) que.push_front(to);
                else que.push_back(to);
            } 
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        //s[l[i]-1]==s[r[i]]
        G[l[i]-1].push_back(P(r[i],0));
        G[r[i]].push_back(P(l[i]-1,0));
    }
    for(int i=0;i<=n-1;i++)
    {
        // |s[i]-s[i+1]|<=1
        G[i].push_back(P(i+1,1));
        G[i+1].push_back(P(i,1));
    }
    bfs();
    for(int i=1;i<=n;i++) if(d[i]==d[i-1]+1) printf("0"); else printf("1");
}