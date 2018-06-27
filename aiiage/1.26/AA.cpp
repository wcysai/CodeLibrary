#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define LL long long
LL n, a[1000005], L[1000005], R[1000005], st[1000005], tre[1000005], G[1000005];
void Update(LL k, LL val)
{
	if(k==0)
		return;
	while(k<=n)
	{
		tre[k] += val;
		k += k&-k;
	}
}
LL Query(LL k)
{
	LL ans = 0;
	while(k)
	{
		ans += tre[k];
		k -= k&-k;
	}
	return ans;
}
int main(void)
{
	LL ans;
	LL i, j, top, now, last;
	scanf("%lld", &n);
	for(i=1;i<=n;i++)
		scanf("%lld", &a[i]);
	top = 0;
	for(i=1;i<=n;i++)
	{
		while(top>=1 && a[st[top]]<=a[i])
			top--;
		L[i] = st[top];
		st[++top] = i;
	}
	top = 0, st[top] = n+1;
	for(i=n;i>=1;i--)
	{
		while(top>=1 && a[st[top]]>=a[i])
			top--;
		R[i] = st[top];
		if(G[R[i]]==0)
			G[R[i]] = i;
		else
			G[R[i]] = min(G[R[i]], i);
		st[++top] = i;
	}
	ans = 1;
	for(i=n;i>=1;i--)
	{
		ans += L[i];
		Update(i, 1);
		Update(L[i], -1);
	}
	/*printf("%lld\n", ans);
	for(i=1;i<=n;i++)
		printf("%lld %lld    %lld %lld\n", L[i], i, i, R[i]);*/
	last = 1000000000;
	for(i=n+1;i>=2;i--)
	{
		if(G[i]==0 || G[i]==i-1)
			continue;
		now = Query(i-1)-Query(G[i]);
		//printf(" %lld  %lld     %lld\n", i, now, i-1-G[i]-now);
		ans -= i-1-G[i]-now;
		if(last<=i-1)
		{
			now = Query(i-1)-Query(last);
			ans += i-1-last-now;
		}
		last = G[i]+1;
	}
	printf("%lld\n", ans);
	return 0;
}
/*
3
3 2 1
*/