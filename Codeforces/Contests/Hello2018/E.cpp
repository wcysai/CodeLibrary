#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,k;
int a[MAXN];
map<int,string> mp;
int main()
{
	mp[15]="x";
	mp[250]="!x";
	mp[51]="y";
	mp[204]="!y";
	mp[85]="z";
	mp[170]="!z";
	mp[3]="x&y";
	mp[252]="!(x&y)";
	mp[0]="x&!x";
	mp[255]="x|!x";
	mp[63]="x|y";
	mp[48]="!x&y";

	return 0;
}