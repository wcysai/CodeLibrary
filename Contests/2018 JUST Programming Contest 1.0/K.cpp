#include<bits/stdc++.h>
#define MAXN 35
#define MAXK 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k;
int cnt[MAXN][MAXN];
bool accepted[MAXN][MAXN];
int problems[MAXN],cnt1[MAXN];
struct submissions
{
	int x,y,z;
	string str;
};
submissions a[MAXK];
bool cmp(submissions p,submissions q)
{
	return p.str<q.str;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(cnt,0,sizeof(cnt));
		memset(accepted,false,sizeof(accepted));
		memset(problems,-1,sizeof(problems));
		for(int i=0;i<k;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			cin>>a[i].str;
		}
		sort(a,a+k,cmp);
		int fst=-1,last=-1,res1=-1,res2=-1,t1=-1,t2=-1;
		for(int i=0;i<k;i++)
		{
			if(a[i].z==1)
			{
				if(problems[a[i].x]==-1) problems[a[i].x]=a[i].y;
				if(!accepted[a[i].y][a[i].x]) 
				{
					if(cnt[a[i].y][a[i].x]==0)
					{
						cnt1[a[i].y]++;
						if((cnt1[a[i].y]>res1)||(cnt1[a[i].y]==res1&&a[i].y<t1))
						{
							res1=cnt1[a[i].y];
							t1=a[i].y;
						}
					}
					if((cnt[a[i].y][a[i].x]>res2)||(cnt[a[i].y][a[i].x]==res2&&a[i].y<t2))
					{
						res2=cnt[a[i].y][a[i].x];
						t2=a[i].y;
					}
				}
				accepted[a[i].y][a[i].x]=true;
				if(fst==-1) fst=a[i].y;
				last=a[i].y;
			}
			else
			{
				cnt[a[i].y][a[i].x]++;
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d ",problems[i]);
		puts("");
		printf("%d %d %d %d\n",fst,last,t1==-1?1:t1,t2);
	}
	return 0;
}