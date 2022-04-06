#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int ans;
vector<ll> bad;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&b[i]); 
		if(b[i]>=a[i]) bad.push_back(i);
		else
		{
			int reach=a[i]-b[i];
			while(bad.size()&&a[bad.back()]>=reach) bad.pop_back();
		}
	}
	//make last not bad
	ans=(int)bad.size();
	int cnt=0,last=(int)bad.size()-1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]>b[i]) continue;
		ans=min(ans,max(b[i]-a[i]+1,cnt));
		if(last>=0&&bad[last]==i) {cnt++; last--;}
	}
	printf("%d\n",ans);
	return 0;
}