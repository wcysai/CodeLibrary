#include<bits/stdc++.h>
#define MAXN 1005
#define INF 200000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
vector<int> G[MAXN];
int id[MAXN][MAXN];
int ev[MAXN],eu[MAXN];
int a[MAXN];
int ord[MAXN],val[MAXN];
int ans[MAXN];
vector<int> v1;
vector<P> v2;
namespace checker
{
	int d[111][111];
	void work()
	{
		for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) 
                d[i][j]=INF;
		for(int i=1;i<=n;i++) d[i][i]=0;
		for(int i=1;i<=m;i++)
		{
			d[eu[i]][ev[i]]=d[ev[i]][eu[i]]=ans[i];
			assert(1<=ans[i]&&ans[i]<=1000000);
		}
		for(int k=1;k<=n;k++) 
            for(int i=1;i<=n;i++) 
                for(int j=1;j<=n;j++) 
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		for(int i=2;i<=n;i++)
		{
			if(a[i]>=0) assert(a[i]==d[1][i]);
			else
			{
				int cnt=0;
				for(int j=1;j<=n;j++) if(d[1][j]<d[1][i]) cnt++;
				assert(a[i]==-cnt);
			}
		}
		puts("done");
	}
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        v1.clear(); v2.clear();
        memset(id,0,sizeof(id));
        memset(val,-1,sizeof(val));
        scanf("%d%d",&n,&m);
        ord[1]=1; v1.push_back(1); val[1]=0;
        for(int i=2;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]<0) 
            {
                ord[i]=-a[i]+1;
                v1.push_back(ord[i]);
            } 
            else ord[i]=0;
            if(a[i]>0)
            {
                val[i]=a[i];
                v2.push_back(P(a[i],i));
            }
        }
        sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
        int cur=0,cnt=0;
        for(int i=0;i<(int)v1.size();i++)
        {
            cnt++;
            if(v1[i]>cnt)
            {
                int dif=v1[i]-cnt;
                for(int j=0;j<dif;j++)
                {
                    int x=v2[cur+j].S;
                    if(j==0) ord[x]=cnt; 
                    else
                    {
                        if(v2[cur+j].F==v2[cur+j-1].F) ord[x]=ord[v2[cur+j-1].S];
                        else ord[x]=cnt+j;
                    } 
                }
                cur+=dif;
                cnt=v1[i];
            }
        }
        if(cur!=(int)v2.size())
        {
            int dif=(int)v2.size()-cur;
            for(int j=0;j<dif;j++)
            {
                int x=v2[cur+j].S;
                if(j==0) ord[x]=cnt; 
                else
                {
                    if(v2[cur+j].F==v2[cur+j-1].F) ord[x]=ord[v2[cur+j-1].S];
                    else ord[x]=cnt+j;
                } 
            }
        }
        v2.clear();
        for(int i=1;i<=n;i++) v2.push_back(P(ord[i],i));
        sort(v2.begin(),v2.end());
        for(int i=0;i<n;i++) 
        {
            int x=v2[i].S;
            if(val[x]!=-1) continue;
            if(v2[i].F==v2[i-1].F) val[x]=val[v2[i-1].S];
            else val[x]=val[v2[i-1].S]+1;
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            eu[i+1]=u; ev[i+1]=v;
            id[u][v]=i+1;
        }
        for(int i=1;i<=m;i++) ans[i]=1000000;
        for(int i=1;i<n;i++)
        {
            int v=v2[i].S;
            bool f=false;
            for(int j=0;j<i;j++)
            {
                int u=v2[j].S;
                if(id[u][v]||id[v][u])
                {
                    int w=max(id[u][v],id[v][u]);
                    f=true;
                    ans[w]=val[v]-val[u];
                    break;
                }
            }
            assert(f);
        }
        printf("Case #%d:",t);
        for(int i=1;i<=m;i++) printf(" %d",ans[i]);
        printf("\n");
        checker::work();
    }
    return 0;
}