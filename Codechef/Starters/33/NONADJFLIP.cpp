#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>str;
		vector<int> v;
		bool adj=false,has=false;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='1') has=true;
			if(i&&str[i]=='1'&&str[i-1]=='1') adj=true;
		}
		if(!has) puts("0"); else if(adj) puts("2"); else puts("1");
	}
	return 0;
}