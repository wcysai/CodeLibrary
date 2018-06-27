#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1e15
using namespace std;
typedef long long ll;
ll n;
struct rect
{
    ll h,w;
}save[MAXN];
vector<rect> a;
ll dp[MAXN],T[MAXN],t,p;
bool cmp(rect x,rect y)
{
    if(x.h==y.h) return x.w>y.w;
    return x.h>y.h;
}
ll Get(ll u, ll v){ return (dp[u]-dp[v]+a[v+1].h-a[u+1].h-1)/(a[v+1].h-a[u+1].h);}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
        scanf("%lld%lld",&save[i].h,&save[i].w);
    sort(save,save+n,cmp);
    a.push_back((rect){0,0});
    for(ll i=0;i<n;i++)
        if(i==0||save[i].w>a[a.size()-1].w)
            a.push_back(save[i]);
    T[t++]=0;
    dp[0]=0;
	for(int i=1;i<=a.size()-1;i++)
	{
		while(t-p>1 && Get(T[p],T[p+1])<=a[i].w) p++;
		dp[i]=a[i].w*a[T[p]+1].h+dp[T[p]];
		while(t-p>1 && Get(T[t-1],i)<=Get(T[t-1],T[t-2])) t--;
		T[t++]=i;
	}
	printf("%lld\n",dp[a.size()-1]);
    return 0;
}
