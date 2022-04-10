#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,m,f[MAXN];
void add_item(int w)
{
	for(int i=w;i<=m;i++) add(f[i],f[i-w]);
}
void erase_item(int w)
{
	for(int i=m;i>=w;i--) dec(f[i],f[i-w]);
}
int main()
{
	scanf("%d%d",&n,&m);
	int ans=0;
	f[0]=1;
	add_item(n);
	//enumerate smallest item,starting from 1
	for(int i=2;i<=n;i++)
	{
		int num=n-i+1;
		if(1LL*num*(num+1)/2<=m) add_item(num*(num+1)/2);
	}
	add(ans,f[m]);
	//shift smallest position
	for(int i=2;i<=n;i++)
	{
		int num=n-i+1;
		if(1LL*num*(num+1)/2<=m) erase_item(num*(num+1)/2);
		num=i-1;
		if(1LL*num*(num+1)/2<=m) add_item(num*(num+1)/2);
		if(1LL*num*(num+1)/2<=m) add(ans,f[m-num*(num+1)/2]);
	}
	printf("%d\n",ans);
	return 0;
}