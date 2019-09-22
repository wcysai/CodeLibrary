#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],c[MAXN],deq[MAXN];
vector<int> v;
void solve()
{
	int s=0,t=0;
	for(int i=0;i<n;i++)
	{
		while(s<t&&a[deq[t-1]]<=a[i]) t--;
		deq[t++]=i;
		if(i-k+1>=0)
		{
			b[i-k+1]=a[deq[s]];
			if(deq[s]==i-k+1)
			{
				s++;
			}
		}
	}
}
void solve2()
{
	int s=0,t=0;
	for(int i=0;i<n;i++)
	{
		while(s<t&&a[deq[t-1]]>=a[i]) t--;
		deq[t++]=i;
		if(i-k+1>=0)
		{
			c[i-k+1]=a[deq[s]];
			if(deq[s]==i-k+1)
			{
				s++;
			}
		}
	}
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    solve(); solve2();
    int ans=0,cnt=0;
    v.clear();
    for(int i=0;i<n;i++)
    {
        if(v.size()&&v.back()>a[i]) v.clear();
        v.push_back(a[i]);
        if(i>=k-1)
        {
            if(v.size()>=k) {cnt++; ans++; continue;}
            if(i==k-1) {ans++; continue;}
            if(a[i]!=b[i-k+1]||a[i-k]!=c[i-k]) ans++;
            //printf("%d %d %d %d %d %d\n",i,a[i],b[i-k+1],a[i-k],c[i-k],ans);
        }
    }
    if(cnt) ans=ans-cnt+1;
    printf("%d\n",ans);
    return 0;
}
