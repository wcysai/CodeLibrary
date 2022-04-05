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
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='B') cnt++;
		else if(str[i]=='A') cnt+=2;
		else 
		{
			for(int i=0;i<cnt/2;i++) printf("A");
			if(cnt&1) printf("B");
			printf("C");
			cnt=0;
		}
	}
	for(int i=0;i<cnt/2;i++) printf("A");
	if(cnt&1) printf("B");
	return 0;
}