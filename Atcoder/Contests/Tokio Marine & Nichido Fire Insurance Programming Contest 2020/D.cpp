#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<P> v1,v2;
int val[MAXN],weight[MAXN];
vector<int> vv1,vv2;
vector<P> queries[MAXN];
int ans[MAXN];
void solve(int v)
{
    vv1.clear(); vv2.clear();
    int sz1=(int)v1.size(),sz2=(int)v2.size();
    sort(vv1.begin(),vv1.end()); sort(vv2.begin(),vv2.end());
}
void dfs(int i,int d)
{
    if(d<=9) v1.push_back(P(val[i],weight[i])); else v2.push_back(P(val[i],weight[i]));
    if(queries[i].size()) solve(i);
    if(i*2<=n) dfs(2*i,d+1);
    if(i*2+1<=n) dfs(2*i+1,d+1);
    if(d<=9) v1.pop_back(); else v2.pop_back();
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&v[i],&w[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        queries[x].push_back(P(y,0));
    }
}