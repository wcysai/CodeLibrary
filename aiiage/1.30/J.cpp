#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int query,n;
int a[MAXN],d[MAXN];
int main()
{
	scanf("%d",&query);
	while(query--)
	{
		scanf("%d",&n);
		int t=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			d[i]=a[i];
		}
		bool f=false,flag=true;
		int cnt=0;
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				f=true;
				swap(a[i],a[i+1]);
			}
			else if(f) {f=false; cnt++;}
		}
		if(f) {cnt++; f=false;}
		for(int i=0;i<n-1;i++)
			if(a[i]>a[i+1]) flag=false;
		if(cnt>1) flag=false;
		if(flag) {puts("Y"); continue;}
		flag=true;
		cnt=0;
		for(int i=n-1;i>0;i--)
		{
			if(d[i]<d[i-1])
			{
				f=true;
				swap(d[i],d[i-1]);
			}
			else if(f) {f=false; cnt++;}
		}
		if(f) cnt++;
		for(int i=n-1;i>0;i--)
			if(d[i]<d[i-1]) flag=false;
		if(cnt>1) flag=false;
		if(flag) {puts("Y"); continue;}
		puts("N");
	}
	return 0;
}