#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
char mp[MAXN][MAXN];
void solve(int num,int l,int r,int pos)
{
	//printf("%d %d %d %d\n",num,l,r,pos);
	for(int i=l;i<=r;i++)
	{
		if(i<pos) mp[num][i]='\\'; else if(i>pos) mp[num][i]='/';
	}
	return;
}
int main()
{
	scanf("%d",&t);
	int kase=0;
	while(t--)
	{
		kase++;
		int res=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(a[0]==0||a[n-1]==0) {printf("Case #%d: IMPOSSIBLE\n",kase); continue;}
		int cnt=0;
		for(int i=0;i<105;i++)
			for(int j=0;j<105;j++)
				mp[i][j]='.';
		for(int i=0;i<n;i++)
		{
			if(a[i]>0)
			{
				int l=cnt,r=cnt+a[i]-1;
				int num=0;
				while(r>=l)
				{
					if(l==r&&i==r) break;
					solve(num,l,r,i);
					l=min(l+1,i);r=max(r-1,i);
					num++;
				}
				res=max(res,num);
				cnt+=a[i];
			}
		}
		printf("Case #%d: %d\n",kase,res+1);
		for(int i=0;i<res;i++)
		{
			for(int j=0;j<n;j++)
				printf("%c",mp[i][j]);
			puts("");
		}
		for(int i=0;i<n;i++) printf(".");
		puts("");
	}
	return 0;
}