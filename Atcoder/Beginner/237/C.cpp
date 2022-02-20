#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str;
int main()
{
	cin>>str;
	n=(int)str.size();
	int l=0,r=n-1;
	while(l<r&&str[r]=='a'&&str[l]=='a') l++,r--;
	while(l<r&&str[r]=='a'&&str[l]!='a')
		r--;
	while(l<r)
	{
		if(str[l]!=str[r])
		{
			puts("No");
			return 0;
		}
		l++; r--;
	}
	puts("Yes");
	return 0;
}