#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,r,c,h,v,num[MAXN],a[MAXN][MAXN],save[MAXN];
string str[MAXN];
int main()
{
	scanf("%d",&t);
	int kase=0;
	while(t--)
	{
		kase++;		
		int sum=0;
		scanf("%d%d%d%d",&r,&c,&h,&v);
		memset(num,0,sizeof(num));
		memset(save,0,sizeof(save));
		for(int i=0;i<r;i++)
			cin>>str[i];
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j]=str[i][j]=='@'?1:0;
		for(int i=1;i<r;i++)
			for(int j=0;j<c;j++)
				a[i][j]+=a[i-1][j];
		for(int i=0;i<r;i++)
		{
			int cnt=0;
			for(int j=0;j<c;j++)
				if(str[i][j]=='@') cnt++;
			num[i]=cnt;
			sum+=cnt;
		}
		printf("Case #%d: ",kase);
		if(sum%((h+1)*(v+1))!=0) {puts("IMPOSSIBLE"); continue;}
		int need=sum/(h+1);
		int cnt=0,last=0;
		bool f=true;
		vector<int> hcut;
		hcut.clear();
		for(int i=0;i<r;i++)
		{
			cnt+=num[i];
			//printf("%d %d\n",cnt,need);
			if(cnt>need) {puts("IMPOSSIBLE"); f=false; break;}
			if(cnt==need) {hcut.push_back(i); cnt=0;}
		}
		/*for(int i=0;i<hcut.size();i++)
			printf("%d ",hcut[i]);
		puts("");*/
		for(int i=0;i<c;i++)
		{
			if(!f) break;
			for(int j=0;j<hcut.size();j++)
				if(j==0) save[j]+=a[hcut[j]][i]; else save[j]+=a[hcut[j]][i]-a[hcut[j-1]][i];
			bool flag=true;
			for(int j=0;j<hcut.size();j++)
			{
				if(save[j]>need/(v+1)) {puts("IMPOSSIBLE"); f=false; break;}
				if(save[j]!=need/(v+1)) flag=false;
			}
			if(flag)
				for(int j=0;j<hcut.size();j++)
					save[j]=0;
		}
		if(f) puts("POSSIBLE");
	}
	return 0;
}