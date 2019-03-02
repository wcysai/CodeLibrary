#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	if(n==3)
	{
		puts("2 5 63");
		return 0;
	}
	set<int> s;
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(9);
	n-=4;
	if(n>14998)
	{
		for(int i=15;i<=29997;i+=12)
		{
			if(n<=14998) break;
			s.insert(i);
			s.insert(i+6);
			n-=2;
		}
	}
	if(n>5000)
	{
		for(int i=8;i<=29996;i+=6)
		{
			s.insert(i);
			s.insert(i+2);
			n-=2;
			if(n<=5000) break;
		}
	}
	for(int i=6;i<=30000;i+=6)
	{
		if(n==0) break;
		s.insert(i);
		n--;
	}
	for(auto it=s.begin();it!=s.end();it++)
		printf("%d ",*it);
	puts("");
	return 0;
}
