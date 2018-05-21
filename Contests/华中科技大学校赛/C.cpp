#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,cnt;
int p[MAXN],r[MAXN],id[MAXN],sz[MAXN],tot;
void init(int n)
{
    for(int i=1;i<=200000;i++)
    {
        p[i]=i;
        r[i]=0;
        id[i]=i;
        sz[i]=1;
    }
    tot=n;
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
    if(r[x]<r[y]) {p[x]=y; sz[y]+=sz[x];}
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        sz[x]+=sz[y];
    }
}
void separate(int u)
{
	sz[find(id[u])]--;
	tot++;
	id[u]=tot;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}

int main()
{
	scanf("%d",&t);
	cnt=0;
	while(t--)
	{
		cnt++;
		scanf("%d%d",&n,&q);
		printf("Case #%d:\n",cnt);
		init(n);
		for(int i=0;i<q;i++)
		{
			int type,u,v;
			scanf("%d",&type);
			if(type==1)
			{
				scanf("%d%d",&u,&v);
				unite(id[u],id[v]);
			}
			else if(type==2)
			{
				scanf("%d",&u);
				separate(u);
			}
			else if(type==3)
			{
				scanf("%d",&u);
				printf("%d\n",sz[find(id[u])]);
			}
			else
			{
				scanf("%d%d",&u,&v);
				if(same(id[u],id[v])) puts("YES"); else puts("NO");
			}
		}
	}
	return 0;
}