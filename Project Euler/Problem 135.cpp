#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
bool find_res(int x)
{
	int cnt=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i!=0) continue;
		int num1=i,num2=x/i;
		if((num1+num2)%4!=0) continue;
		int d=(num1+num2)/4;
		if(num2>d) cnt++;
		if(num1>d&&num1!=num2) cnt++;
		if(cnt>=2) return false;
	}
	return cnt;
}
int main()
{
	int ans=0;
	for(int i=1;i<1000000;i++)
	{
		if(find_res(i)==10)
		{
			//printf("%d\n",i);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}