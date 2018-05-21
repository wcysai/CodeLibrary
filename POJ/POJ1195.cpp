#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1024
using namespace std;
typedef long long ll;
int a,b,c,d;
int bit[MAXN+1][MAXN+1];
int n;
ll sum(int x,int y)
{
	int s=0;
	for(int i=x;i>0;i-=i&-i)
	  for(int j=y;j>0;j-=j&-j)
	    s+=bit[i][j];
	    return s;
 } 
 void add(int x,int y,int d)
 {
 	for(int i=x;i<n+1;i+=i&-i)
 	  for(int j=y;j<n+1;j+=j&-j)
 	    bit[i][j]+=d;
 }
 int main()
 {
 	int h;
 	memset(bit,0,sizeof(bit));
 	scanf("%d %d",&h,&n);
 	do
 	{
 		scanf("%d",&h);
 		if(h==3) break;
 		if(h==1)
 		{
 			int t;
 			scanf("%d%d%d",&a,&b,&t);
 			add(a+1,b+1,t);
		 }
		 if(h==2)
		 {
		 	scanf("%d%d%d%d",&a,&b,&c,&d);
		 	printf("%lld\n",sum(c+1,d+1)+sum(a,b)-sum(a,d+1)-sum(c+1,b));
		 }
	 }
	 while(true);
	 return 0;
 }