#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
vector<int> odd,even;

int main()
{
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&b[i]);
		b[i]-=a[i];
		if(i&1) odd.push_back(b[i]); else even.push_back(b[i]);
	}
	sort(odd.begin(),odd.end()); sort(even.begin(),even.end());
	while(odd.size())
	{
		if(even.back()+odd.back()>0)
		{
			ans+=even.back()+odd.back();
			even.pop_back(); odd.pop_back();
		}
		else break;
	}
	printf("%lld\n",ans);
	return 0;
}