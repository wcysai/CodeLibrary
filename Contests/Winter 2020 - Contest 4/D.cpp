#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
struct edge{int to,id;};
vector<edge> G[7];
vector<int> loop[7];
map<char,int> mp;
bool vis[MAXN];
bool cloop[7];
vector<int> tour;
void add_edge(int u,int v,int id)
{
    G[u].push_back((edge){v,id});
}
void dfs(int v)
{
    for(auto e:G[v])
    {
        if(!vis[e.id])
        {
            vis[e.id]=true;
            dfs(e.to);
            tour.push_back(e.id);
        }
    }
}
int main()
{
    mp['d']=1; mp['e']=2; mp['p']=3; mp['a']=4; mp['r']=5; mp['t']=6;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        int len=str.size();
        int x=mp[str[0]],y=mp[str[len-1]];
        y++; if(y>6) y-=6;
        add_edge(x,y,i);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    for(int i=(int)tour.size()-1;i>=0;i--) printf("%d\n",tour[i]);
    return 0;
}