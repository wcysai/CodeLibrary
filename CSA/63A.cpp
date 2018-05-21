#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	int cnt=0;
	for(int i=0;i+n<=m;i++)
	{
		bool f=true;
		for(int j=0;j<n;j++)
			if(a[j]+b[i+j]!=1) {f=false; break;}
		if(f) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}