#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
vector<int> v;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		v.clear();
		for(int i=0;i<N;i++)
		{
			int x; scanf("%d",&x);
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		int now=0;
		for(int i=0;i<(int)v.size();i++)
		{
			if(v[i]!=now) break;
			else now++;
		}
		if(now==1) puts("-1");
		else if(now==0) printf("%d\n",v[0]-1);
		else
		{
			int cnt=1,ans=0;
			for(int i=1;i<(int)v.size();i++)
			{
				if(v[i]>v[i-1]+1) 
				{
					if(cnt>=now-1) ans++;
					cnt=1;
				}
				else cnt++;
			}
			if(cnt>=now-1) ans++;
			printf("%d\n",ans-1);
		}
	}
	return 0;
}