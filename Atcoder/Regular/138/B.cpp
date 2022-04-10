#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4000005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int flip;
int main()
{
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	l=1; r=n;
	while(l<=r)
	{
		if((a[l]^flip)&&(a[r]^flip)) {puts("No"); return 0;}
		if(!(a[r]^flip)) r--;
		else {l++; flip^=1;}
	}
	puts("Yes");
	return 0;
}