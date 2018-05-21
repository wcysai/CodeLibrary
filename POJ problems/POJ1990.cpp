#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring> 
#define MAXN 20000
using namespace std;
typedef long long ll;
ll dis[MAXN+1],cnt[MAXN+1];
int n;
pair<ll,ll> a[MAXN+1];
ll sum(ll *b,int i)
{
	int s=0;
	while(i>0)
	{
		s+=b[i];
		i-=i&-i;
	}
	return s;
 } 
 void add(ll *b,int i,int v)
 {
 	while(i<=MAXN)
 	{
 		b[i]+=v;
 		i+=i&-i;
	 }
 }
 int main()
 {
 	scanf("%d",&n);
 	ll s=0;
 	memset(dis,0,sizeof(dis));
 	memset(cnt,0,sizeof(cnt));
 	for(int i=1;i<=n;i++) 
 	{
 	  scanf("%I64d %I64d",&a[i].first,&a[i].second);
    }
    
 	sort(a+1,a+n+1);
 	ll ans=0;
 	for(int i=1;i<=n;i++)
 	{
 	  s+=a[i].second;
 	  add(cnt,a[i].second,1);
 	  add(dis,a[i].second,a[i].second);
 	  ans+=(a[i].second*sum(cnt,a[i].second-1)-sum(dis,a[i].second-1)+s-a[i].second-sum(dis,a[i].second-1)-(i-1-sum(cnt,a[i].second-1))*a[i].second)*a[i].first;
    }
 	printf("%I64d",ans);
 	return 0;
}