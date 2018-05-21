#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int t,A;
bool used[9];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&A);
		int now=2,cnt=9,x,y;
		bool f=false;
		for(int i=1;i<=23;i++)
		{
			memset(used,false,sizeof(used));
			cnt=9;
			while(cnt>0)
			{
				printf("%d %d\n",2,now);
				fflush(stdout);
				scanf("%d%d",&x,&y);
				if(x==0&&y==0) {f=true; break;}
				int id=(x-1)*3+y-now+1;
				if(!used[id]) {cnt--; used[id]=true;} 
			}
			now+=3;
			if(f) break;
		}
	}
	return 0;
}