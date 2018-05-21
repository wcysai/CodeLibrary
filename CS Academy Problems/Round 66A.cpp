#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,m;
int a[MAXN],b[MAXN];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d%d",&n,&m);
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	sort(a,a+n,cmp);
	sort(b,b+m,cmp);
	for(int i=0;i<min(m,n);i++)
		if(a[i]>b[i]) cnt1++; else cnt2++;
	printf("%d %d\n",cnt1,cnt2);
	return 0;
}