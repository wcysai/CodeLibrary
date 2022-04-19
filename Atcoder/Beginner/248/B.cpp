#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll a,b,k;
int main()
{
	cin>>a>>b>>k;
	int cnt=0;
	while(a<b) cnt++,a*=k;
	cout<<cnt<<endl;
	return 0;	
}