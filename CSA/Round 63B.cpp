#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int q,k;
double s;
int a[MAXN];
int main()
{
	scanf("%lf",&s);
	scanf("%d%d",&q,&k);
	for(int i=0;i<q;i++)
		scanf("%d",&a[i]);
	sort(a,a+q);
	for(int i=0;i<q;i++)
		if((double)k>s*a[i]/100) s+=k; else s+=s*a[i]/100;
	printf("%f\n",s);
	return 0;
}