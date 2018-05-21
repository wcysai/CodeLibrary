#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int n;
int h[MAXN];
int L[MAXN],R[MAXN];
int st[MAXN];
void solve()
{
	int t=0;
	for(int i=0;i<n;i++)
	{
		while(t>0&&h[st[t-1]]<=h[i]) t--;
		L[i]=t==0?0:(st[t-1]+1);
		st[t++]=i;
	}
	t=0;
	for(int i=n-1;i>=0;i--)
	{
		while(t>0&&h[st[t-1]]<=h[i]) t--;
		R[i]=t==0?n+1:(st[t-1]+1);
		st[t++]=i;
	}
	int ans=0;
	for(int i=0;i<n;i++)
        printf("%d %d\n",L[i],R[i]);
	for(int i=0;i<n;i++)
    {
        if(L[i]!=0) ans=max(ans,i+1-L[i]);
        if(R[i]!=n+1) ans=max(ans,R[i]-i);
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    solve();
    return 0;
}
