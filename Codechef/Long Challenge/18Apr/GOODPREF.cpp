#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t;
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		scanf("%d",&n);
		int k=str.size();
		int num=min(n,k);
		int cnt=0,ans=0;
		for(int i=0;i<num;i++)
			for(int j=0;j<k;j++)
			{
				if(str[j]=='a') cnt++; else cnt--;
				if(cnt>0) ans++;
			}
		if(cnt==0) {printf("%lld\n",(ll)ans/num*n); continue;}
		if(cnt<0) {printf("%d\n",ans); continue;}
		if(cnt>0) {printf("%lld\n",(ll)ans+(ll)(n-num)*str.size()); continue;}
	}
	return 0;
}