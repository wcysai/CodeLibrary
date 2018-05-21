#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> num[6];
bool vis[6];
bool f;
int a[6];
void dfs(int dep)
{
	if(f) return;
	if(dep==6)
	{
		if(a[5]%100==a[0]/100)
		{
			f=true;
			printf("%d %d %d %d %d %d\n%d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[0]+a[1]+a[2]+a[3]+a[4]+a[5]);
		}
		return;
	}
	for(int i=0;i<6;i++)
	{
		if(!vis[i])
		{
			for(int j=0;j<num[i].size();j++)
			{
				if(dep==0||num[i][j]/100==a[dep-1]%100)
				{
					a[dep]=num[i][j];
					vis[i]=true;
					dfs(dep+1);
					vis[i]=false;
				}
			}
		}
	}
	return;
}
int main()
{
	for(int i=1;i<=200;i++)
		if(i*(i+1)/2>=1000&&i*(i+1)/2<=9999) num[0].push_back(i*(i+1)/2);
	for(int i=1;i<=100;i++)
		if(i*i>=1000&&i*i<=9999) num[1].push_back(i*i);
	for(int i=1;i<=200;i++)
		if(i*(3*i-1)/2>=1000&&i*(3*i-1)/2<=9999) num[2].push_back(i*(3*i-1)/2);
	for(int i=1;i<=200;i++)
		if(i*(2*i-1)>=1000&&i*(2*i-1)<=9999) num[3].push_back(i*(2*i-1));
	for(int i=1;i<=200;i++)
		if(i*(5*i-3)/2>=1000&&i*(5*i-3)/2<=9999) num[4].push_back(i*(5*i-3)/2);
	for(int i=1;i<=200;i++)
		if(i*(3*i-2)>=1000&&i*(3*i-2)<=9999) num[5].push_back(i*(3*i-2));
	memset(vis,false,sizeof(vis));
	memset(a,0,sizeof(a));
	dfs(0);
	return 0;
}