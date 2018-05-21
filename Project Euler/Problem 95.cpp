#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int d[MAXN];
int V;
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN],cnt[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=V;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
	memset(d,0,sizeof(d));
	for(int i=1;i<=500000;i++)
		for(int j=2*i;j<=1000000;j+=i)
			d[j]+=i;
	V=1000000;
	for(int i=1;i<=1000000;i++)
		if(d[i]<=1000000) add_edge(i,d[i]);
	int p=scc();
	int t=-1,res=-1;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=1000000;i++)
		cnt[cmp[i]]++;
	for(int i=0;i<p;i++)
		if(cnt[i]>res) {res=cnt[i]; t=i;}
	for(int i=1;i<=1000000;i++)
		if(cmp[i]==t) {printf("%d\n",i); return 0;}
	printf("%d\n",p);
	return 0;
}