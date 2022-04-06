#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
vector<int> vs,vt;
int main()
{
	scanf("%d",&n);
	cin>>s>>t;
	ll ans=0;
	for(int i=0;i<n;i++) if(s[i]=='1') vs.push_back(i);
	for(int i=0;i<n;i++) if(t[i]=='1') vt.push_back(i);
	reverse(vs.begin(),vs.end());
	reverse(vt.begin(),vt.end());
	while(vt.size())
	{
		if(!vs.size()) {puts("-1"); return 0;}
		if(vt.back()>vs.back())
		{
			if(vs.size()<2) {puts("-1"); return 0;}
			int x=vs.back(); vs.pop_back();
			int y=vs.back(); vs.pop_back();
			ans+=y-x;
			continue;
		}
		ans+=vs.back()-vt.back();
		vs.pop_back(); vt.pop_back();
	}
	if((int)vs.size()&1) {puts("-1"); return 0;}
	while(vs.size())
	{
		int x=vs.back(); vs.pop_back();
		int y=vs.back(); vs.pop_back();
		ans+=y-x;
	}
	printf("%lld\n",ans);
	return 0;
}