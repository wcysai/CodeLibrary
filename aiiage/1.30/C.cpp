#include<bits/stdc++.h>
#define MAXN 1050
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
struct edge
{
	int to,id;
};
int t,n,m;
int p[MAXN],r[MAXN];
P E[MAXN];
bool used[MAXN],valid[MAXN];
int dp[MAXN][2];
vector<edge> G[MAXN];
vector<P> choice;
void init(int n)
{
	
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int ans;
int dfs(int v,int p,int state)
{
	if(dp[v][state]!=-1) return dp[v][state];
	if(state==1)
	{
		int s=0;
		for(int i=0;i<G[v].size();i++)
		{
			int to=G[v][i].to,id=G[v][i].id;
			if(to==p||!valid[id]) continue;
			s+=min(dfs(to,v,0),dfs(to,v,1));
		}
		return dp[v][state]=s;
	}
	else
	{
		int s=0;
		for(int i=0;i<G[v].size();i++)
		{
			int to=G[v][i].to,id=G[v][i].id;
			if(to==p||!valid[id]) continue;
			s+=1+dfs(to,v,1);
		}
		return dp[v][state]=s;
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			G[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&E[i].F,&E[i].S);
			E[i].F--;
			E[i].S--;
			G[E[i].F].push_back((edge){E[i].S,i});
			G[E[i].S].push_back((edge){E[i].F,i});
		}
		init(n);
		for(int i=0;i<m;i++)
		{
			if(same(E[i].F,E[i].S))
				choice.push_back(E[i]);
			else unite(E[i].F,E[i].S);
		}
		int sz=choice.size();
		int res=0,cnt=0;
		for(int i=0;i<(1<<sz);i++)
		{
			ans=0;
			memset(used,false,sizeof(used));
			memset(valid,true,sizeof(valid));
			memset(dp,-1,sizeof(dp));
			vector<int> vert;
			vert.clear();
			for(int j=0;j<sz;j++)
				if((i<<j)&1) {if(!used[choice[j].F]) ans++; used[choice[j].F]=true; vert.push_back(choice[j].F);} else {if(!used[choice[j].S]) ans++; used[choice[j].S]=true; vert.push_back(choice[j].S);}
			for(int j=0;j<vert.size();j++)
			{
				for(int k=0;k<G[vert[j]].size();k++)
					valid[G[vert[j]][k].id]=false;
			}
			for(int j=0;j<n;j++)
				if(!used[j]) ans+=min(dfs(j,-1,0),dfs(j,-1,1));
			if(ans==res) cnt++; else if(ans>res) {res=ans; cnt=1;}
		}
		printf("%d %d\n",res,cnt);
	}
    return 0;
}
