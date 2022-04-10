#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
string str;
int main()
{
	cin>>str;
	n=(int)str.size();
	printf("0");
	cout<<str.substr(0,n-1)<<endl;
	return 0;
}