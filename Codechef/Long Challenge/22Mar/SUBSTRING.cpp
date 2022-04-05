#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		int cnt=0,ans=0;
		int n=(int)str.size();
		for(int i=1;i<n-1;i++)
		{
			if(str[i]==str[0]||str[i]==str[n-1])
			{
				ans=max(ans,cnt);
				cnt=0;
			}
			else cnt++;
		}
		ans=max(ans,cnt);
		if(ans==0) puts("-1"); else printf("%d\n",ans);
	}
	return 0;
}