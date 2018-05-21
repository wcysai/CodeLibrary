#include<bits/stdc++.h>
#define MAXN 35
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,d;
string str;
ll find_ans()
{
	ll sum=0,now=1;
	for(int i=0;i<n;i++)
			if(str[i]=='C') now*=2; else sum+=now;
	return sum;
}
int main()
{
	scanf("%d",&t);
	int casecnt=0;
	while(t--)
	{
		casecnt++;
		scanf("%d",&d);
		cin>>str;
		printf("Case #%d: ",casecnt);
		n=str.size();
		int cnt=0;
		bool f=true;
		while(find_ans()>d)
		{
			f=false;
			for(int i=n-2;i>=0;i--)
			{
				if(str[i]=='C'&&str[i+1]=='S')
				{
					swap(str[i],str[i+1]);
					cnt++;
					f=true;
					break;
				}
			}
			if(!f) break;
		}
		if(f) printf("%d\n",cnt); else puts("IMPOSSIBLE");
	}
	return 0;
}