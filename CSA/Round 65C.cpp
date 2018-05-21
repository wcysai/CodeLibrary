#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
using namespace std;
struct edge{int to,length;};
int N,K;
vector<edge> G[MAXN];
bool centroid[MAXN];
int subtree_size[MAXN];
int ans;
int compute_subtree_size(int v,int p)
{
    int c=1;
    for(int i=0;i<G[v].size();i++)
    {
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        c+=compute_subtree_size(G[v][i].to,v);
    }
    subtree_size[v]=c;
    return c;
}
pair<int,int> search_centroid(int v,int p,int t)
{
    pair<int,int> res=make_pair(INT_MAX,-1);
    int s=1,m=0;
    for(int i=0;i<G[v].size();i++)
    {
        int w=G[v][i].to;
        if(w==p||centroid[w]) continue;
        res=min(res,search_centroid(w,v,t));
        m=max(m,subtree_size[w]);
        s+=subtree_size[w];
    }
    m=max(m,t-s);
    res=min(res,make_pair(m,v));
    return res;
}
int solve_subproblem(int v)
{
    compute_subtree_size(v,-1);
    int s=search_centroid(v,-1,subtree_size[v]).second;
    centroid[s]=true;
    vector<int> ds;
    for(int i=0;i<G[s].size();i++)
    {
        if(centroid[G[s][i].to]) continue;
        ds.push_back(solve_subproblem(G[s][i].to)+G[s][i].length);
    }
    int sum=0,maxx=-INF,maxy=-INF;
    centroid[s]=false;
    if(ds.size()==0) return 0;
    if(ds.size()==1) return ds[0];
    for(int i=0;i<ds.size();i++)
    {
    	sum+=ds[i];
    	if(ds[i]>maxx)
    	{
    		maxy=maxx;
    		maxx=ds[i];
    	}
    	else if(ds[i]>maxy) maxy=ds[i];
    }
    return sum*2-maxx-maxy;
}
int main()
{
   	scanf("%d",&N);
   	for(int i=0;i<N-1;i++)
   	{
   		int x,y;
   		scanf("%d%d",&x,&y);
   		G[x-1].push_back((edge){y-1,1});
   		G[y-1].push_back((edge){x-1,1});
   	}
   	printf("%d\n",solve_subproblem(0));
   	return 0;
}
