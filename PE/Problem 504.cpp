#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int find_num(int a,int b,int c,int d)
{
	int area=(a+c)*(b+d);
	int num=gcd(a,b)+gcd(b,c)+gcd(c,d)+gcd(d,a);
	return (area+2-num)/2;
}
bool issqr(int x)
{
	int p=(int)sqrt(x);
	return p*p==x;
}
int main()
{
	int ans=0;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			for(int k=1;k<=100;k++)
				for(int l=1;l<=100;l++)
					if(issqr(find_num(i,j,k,l))) ans++;
	printf("%d\n",ans);
	return 0;
}