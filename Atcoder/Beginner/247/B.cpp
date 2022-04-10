#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
string s[MAXN],t[MAXN];
map<string,int> mp;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>s[i]; cin>>t[i];
		mp[s[i]]++; mp[t[i]]++;
	}
	bool f=true;
	for(int i=0;i<n;i++)
		if(mp[s[i]]!=1&&mp[t[i]]!=1&&(!(s[i]==t[i]&&mp[s[i]]==2))) f=false;
	if(f) puts("Yes"); else puts("No");
	return 0;
}