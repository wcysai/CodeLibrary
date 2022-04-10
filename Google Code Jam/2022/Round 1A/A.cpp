#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
string str;
int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		cin>>str;
		n=(int)str.size();
		vector<pair<char,int> > v;
		char ch=str[0];
		int cnt=1;
		for(int i=1;i<n;i++)
		{
			if(str[i]==str[i-1])
			{
				cnt++;
			}
			else
			{
				v.push_back(make_pair(ch,cnt));
				ch=str[i]; cnt=1;
			}
		}
		v.push_back(make_pair(ch,cnt));
		printf("Case #%d: ",t);
		for(int i=0;i<(int)v.size()-1;i++)
		{
			int num=v[i].S;
			if(v[i].F<v[i+1].F) num*=2;
			for(int j=0;j<num;j++) printf("%c",v[i].F);
		}
		for(int j=0;j<(int)v.back().S;j++)
			printf("%c",v.back().F);
		printf("\n");
	}
	return 0;
}