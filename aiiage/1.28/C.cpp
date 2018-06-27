#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int t,n;
int a[MAXN],num[MAXN],occ[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int cnt=0,dummy=-1;
		memset(num,0,sizeof(num));
		memset(occ,0,sizeof(occ));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			occ[a[i]]++;
			if(i!=0&&a[i]==a[i-1]) num[a[i]]++;
			if((n&1)&&occ[a[i]]==(n+1)/2) dummy=a[i];
			else if(occ[a[i]]>n/2) dummy=-2;
		}
		if(dummy==-2) {puts("-1"); continue;}
		else if(dummy!=-1)
		{
			for(int i=n-1;i>=0;i--)
			{
				if(a[i]==dummy) break;
				if(i==n-1||a[i]!=a[i+1]) num[a[i]]++;
			}
		}
		int lmax=0,save=-1;
		for(int i=1;i<=n;i++)
		{
			cnt+=num[i];
			if(num[i]>lmax)
			{
				lmax=num[i];
				save=i;
			}
		}
		if(a[0]==save) printf("%d\n",max(lmax*2,cnt));
		else printf("%d\n",max(lmax*2-1,cnt));
	}
	return 0;
}