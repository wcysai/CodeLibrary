#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,c,q;
struct edge
{
    int to,color;
};
unordered_map<int,int> v[MAXN];
vector<edge> G[MAXN];
vector< vector<int> > cG[MAXN];
int tot[MAXN];
int p[MAXN];
set<int> has[MAXN];
vector<int> dsu[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        dsu[i].push_back(i);
    }
}
void unite(int x,int y)
{
    if(p[x]==p[y]) return;
    if(dsu[p[x]].size()<dsu[p[y]].size()) 
    {
        for(int i=0;i<(int)dsu[p[x]].size();i++)
        {
            int v=dsu[p[x]][i];
            for(auto e:G[v])
            {
                int to=e.to;
                has[to].erase(p[v]);
                has[to].insert(p[y]);
            }
            p[v]=p[y];
        }
        dsu[p[y]].insert(dsu[p[y]].begin(),dsu[p[x]].begin(),dsu[p[x]].end());
        dsu[p[x]].clear();
    }
    else
    {
        for(int i=0;i<(int)dsu[p[y]].size();i++)
        {
            int v=dsu[p[y]][i];
            for(auto e:G[v])
            {
                int to=e.to;
                has[to].erase(p[v]);
                has[to].insert(p[x]);
            }
            p[v]=p[x];
        }
        dsu[p[x]].insert(dsu[p[x]].begin(),dsu[p[y]].begin(),dsu[p[y]].end());
        dsu[p[y]].clear();
    }
}
char str[5];
int main()
{
    scanf("%d%d%d%d",&n,&m,&c,&q);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].push_back((edge){y,z});
        G[y].push_back((edge){x,z});
        if(!v[x][z]) 
        {
            v[x][z]=tot[x]++;
            cG[x].resize(tot[x]);
            cG[x][tot[x]].push_back(y);
        }
        else cG[x][v[x][z]].push_back(y);
        if(!v[y][z]) 
        {
            v[y][z]=tot[y]++;
            cG[y].resize(tot[y]);
            cG[y][tot[y]].push_back(x);
        }
        else cG[y][v[y][z]].push_back(x);
    }
    init(n);
    for(int i=1;i<=n;i++)
    {
        for(auto e:G[i])
        {
            int to=e.to;
            has[i].insert(to);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)cG[i].size();j++)
            for(int k=1;k<(int)cG[i][j].size();k++)
                unite(cG[i][j][k-1],cG[i][j][k]);
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        if(str[0]=='+')
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            G[x].push_back((edge){y,z});
            G[y].push_back((edge){x,z});
            if(!v[x][z]) 
            {
                v[x][z]=tot[x]++;
                cG[x].resize(tot[x]);
                cG[x][tot[x]].push_back(y);
            }
            else cG[x][v[x][z]].push_back(y);
            if(!v[y][z]) 
            {
                v[y][z]=tot[y]++;
                cG[y].resize(tot[y]);
                cG[y][tot[y]].push_back(x);
            }
            else cG[y][v[y][z]].push_back(x);
        }
    }
    return 0;
}

