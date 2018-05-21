#include<bits/stdc++.h>
#define N 100005
using namespace std;
int a[N],c[N];
int n,m,v[20];
int f[N],ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x]^=z; a[y]^=z;
	}
	for (int i=0;i<n;i++)
		c[a[i]]++;
	for (int i=1;i<16;i++)
	{
		ans+=c[i]/2;
		if (c[i]&1) v[m++]=i;
	}
	f[0]=0;
	for (int i=1;i<1<<m;i++)
	{
		int k=0,x=0;
		for (int j=0;j<m;j++)
			if ((i>>j)&1)
			{
				x^=v[j];
				k++;
			}
		f[i]=(x?100:k-1);
		for (int p=i-(i&(-i)),j=p;;j=(j-1)&p)
		{
			f[i]=min(f[i],f[j]+f[i^j]);
			if (!j) break; 
		}
	}
	printf("%d",ans+f[(1<<m)-1]);
}