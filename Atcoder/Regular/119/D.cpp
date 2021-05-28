#include<bits/stdc++.h>
#define MAXN 2505
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str[MAXN];
vector<P> G[2*MAXN];
void add_edge(int u,int v,int id)
{
    G[u].push_back(P(v,id));
    G[v].push_back(P(u,id));
}
bool vis[2*MAXN];
int cntl,cntr;
void dfs(int v,bool print=false)
{
    vis[v]=true;
    if(v<=n) cntl++; else cntr++;
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(!vis[to]) 
        {
            dfs(to,print);
            if(print) printf("%c %d %d\n",to<=n?'X':'Y',id/m+1,id%m+1);
        }
    }
}
P calc(int type,bool print=false)
{
    memset(vis,false,sizeof(vis));
    int st=(type?n+1:1),ed=(type?n+m:n);
    int x=n,y=m,del=0;
    for(int i=st;i<=ed;i++) 
    {
        if(!vis[i])
        {
            cntl=cntr=0;
            dfs(i,print);
            if(i<=n) cntl--; else cntr--;
            x-=cntl; y-=cntr;
            del+=cntl; del+=cntr;
        }
    }
    return P(n*m-x*y,del);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) cin>>str[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(str[i][j]=='R') add_edge(i+1,n+j+1,i*m+j);
    if(calc(0)>calc(1)) 
    {
        printf("%d\n",calc(0).S);
        calc(0,true);
    }
    else
    {
        printf("%d\n",calc(1).S);
        calc(1,true);
    }
    return 0;
}