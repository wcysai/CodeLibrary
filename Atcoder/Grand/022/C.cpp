#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN],b[MAXN],dis[MAXN][MAXN];
bool f[MAXN][MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	memset(f,false,sizeof(f));
    for (int i=0;i<n;i++) f[i][a[i]]=true;
	for(int i=0;i<=50;i++)
		for(int j=0;j<=50;j++)
			dis[i][j]=i==j?0:INF;
	for(int i=0;i<=50;i++)
		for(int j=1;j<=i;j++)
			dis[i][i%j]=min(dis[i][i%j],j);
	for(int k=0;k<=50;k++)
        for(int i=0;i<=50;i++)
          for(int j=0;j<=50;j++) dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
	for(int i=0;i<n;i++)
		if(dis[a[i]][b[i]]==INF) {puts("-1"); return 0;}
    ll ans=0;
	for(int i=50;i>=1;i--)
    {
        bool g=false;
        for(int j=0;j<n;j++)
        {
            int r=51;
            for (int k=0;k<=50;k++) if(f[j][k]) r=min(r,dis[k][b[j]]);
            if (r==i) g=true;
        }
        if(g) 
        {
            ans+=1LL<<i;
            for(int j=0;j<n;j++)
                for(int k=0;k<=50;k++)
                    f[j][k%i]|=f[j][k];
        }
    }
	printf("%lld\n",ans);
	return 0;
}
