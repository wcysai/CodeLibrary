#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,x,a[MAXN],b[MAXN],num[MAXN];
map<int,int> mp;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
			mp[a[i]]=i;
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)
			num[mp[b[i]]]=i;
		for(int i=1;i<=q;i++)
		{
			scanf("%d",&x);
			int low,high,mid,cntless,cntmore,needless,needmore;
	   		low=1;high=n;
	   		cntless=cntmore=needless=needmore=0;
	   		int pos=mp[x];
	    	while(low<=high)
	    	{
	        	mid=(low+high)/2;
	        	if(a[mid]==x) break;
	        	if(mid<pos)
	        	{
	        		needless++;
	        		if(a[mid]>x) cntless++;
	        		low=mid+1;
	        	}
	        	else
	        	{
	        		needmore++;
	        		if(a[mid]<x) cntmore++;
	        		high=mid-1;
	        	}
	    	}
	    	int id=num[mp[x]];
	    	if(needless>=id||needmore>=n-id+1) puts("-1"); else printf("%d\n",max(cntmore,cntless));
	   	}
	}
	return 0;
}