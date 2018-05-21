#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring> 
#define MAXN 1000
using namespace std;
int bit[MAXN+2][MAXN+2];
int n,t;
char str[2];
typedef long long ll;
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
 	int m;
 	scanf("%d",&m);
 	for(int j=0;j<m;j++)
 	{
 	scanf("%d%d",&n,&t);
 	memset(bit,0,sizeof(bit));
 	for(int i=0;i<t;i++)
 	{
 		scanf("%s",str);
 		if(str[0]=='C')
 		{
 			int x1,y1,x2,y2;
 			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
 			add(x1,y1,1);
			add(x2+1,y1,-1);
			add(x1,y2+1,-1);
			add(x2+1,y2+1,1);
 	   }
 	   else
 	   {
 	   	   int x,y;
 	   	   scanf("%d%d",&x,&y);
 	   	   printf("%d\n",sum(x,y)%2);
		}
	 }
	 printf("\n");
}
 	return 0;
  } 