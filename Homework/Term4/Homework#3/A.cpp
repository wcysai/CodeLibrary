#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l;
multiset<int> s;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		scanf("%d",&n);
		scanf("%d",&l);
		int x;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			s.insert(x);
		}
		int cnt=0;
		while(s.size())
		{
			int t=*s.begin();
			s.erase(s.begin());
			if(s.size())
			{
				auto it=s.upper_bound(l-t);
				if(it!=s.begin())
				{
					it--;
					s.erase(it);
				}
			}
			cnt++;
		}
		printf("%d\n",cnt);
		if(t>0) puts(""); 
	}
	return 0;
}