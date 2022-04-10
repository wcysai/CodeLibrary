#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,K,cur,num;
bool vis[MAXN];
mt19937 wcy(time(NULL));
vector<int> id;
ll ans;
void reconstruct()
{
	vector<int> tmp;
	for(auto x:id) if(!vis[x]) tmp.push_back(x);
	id=tmp;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&N,&K);
		for(int i=1;i<=N;i++) vis[i]=0;
		ll sum=0;
		int cnt=0,cc=0;
		if(N<=K)
		{
			for(int i=1;i<=K+1;i++)
			{
				scanf("%d%d",&cur,&num);
				if(!vis[cur])
				{
					sum+=num; 
					cnt++;
				}
				if(i==K+1)
				{
					printf("E %lld\n",sum/2);
					fflush(stdout);
				}
				else 
				{
					printf("T %d\n",i);
					fflush(stdout);
				}
			}
			continue;
		}
		id.clear();
		for(int i=1;i<=N;i++) id.push_back(i);
		for(int i=1;i<=K+1;i++)
		{
			scanf("%d%d",&cur,&num);
			if(!vis[cur]) cc++;
			sum+=num; vis[cur]=true;
			cnt++; 
			if(i==K+1) { printf("E %lld\n",sum*N/cnt/2); fflush(stdout); break;}
			if(i%20==0)
			{
				if(cc*2>=(int)id.size())
				{
					reconstruct();
					cc=0;
				}
				int x=wcy()%N+1;
				printf("T %d\n",x); 
				fflush(stdout);
				break;
			}
			else {printf("W\n"); fflush(stdout);}
		}
	}
	return 0;
}