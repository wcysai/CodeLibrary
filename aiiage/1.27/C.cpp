#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t;
string dict,art;
map<string,int> mymap;
multiset<int> s;
int a[MAXN];
int main()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		getline(cin,art);
		getline(cin,dict);
		mymap.clear();
		memset(a,0,sizeof(a));
		int n=dict.size(),now=0,cnt=0;
		for(int i=0;i<=n;i++)
		{
			if(i==n||dict[i]==' ') 
			{
				string str=dict.substr(now,i-now);
				mymap[str]=cnt++;
				now=i+1;
			}
		}
		int m=art.size();
		int num=0;
		now=0;
		for(int i=0;i<=m;i++)
		{
			if(i==m||art[i]==' ')
			{
				string str=art.substr(now,i-now);
				a[num++]=mymap[str];
				now=i+1;
			}
		}
		s.clear();
		int ans=0;
		for(int i=0;i<num;i++)
		{
			auto lb=s.lower_bound(a[i]);
			if(lb==s.begin())
			{
				ans++;
				s.insert(a[i]);
			}
			else 
			{
				lb--;
				lb=s.erase(lb);
				s.insert(a[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}