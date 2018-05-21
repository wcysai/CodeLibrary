#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX_N 20
using namespace std;
const int dx[4]={1,0,1,0};
const int dy[4]={0,1,1,0};
int dir[MAX_N];
int f[MAX_N];
int calc()
{
	memset(f,0,sizeof(f));
	int res=0;
	int sum=0;
	for(int i=0;i<=17;i++)
	{
		if((dir[i]+sum)%2!=0)
		{
		   res++;
		   f[i]=1;
		}
		sum+=f[i];
		if(i-2>=0) sum-=f[i-2];
	}
	for(int i=18;i<20;i++)
	{
	  if((dir[i]+sum)%2!=0) return -1;
	  sum-=f[i-2];
    }
   return res;
}
void pro(int x,int y)
{
	if(x==1)
	{
		dir[0]=1-dir[0];
		dir[1]=1-dir[1];
	 } 
	 if(y==1)
	{
		dir[18]=1-dir[18];
		dir[19]=1-dir[19];
	 } 
}
void solve()
{
	int M=20;
	for(int i=0;i<4;i++)
	{
		pro(dx[i],dy[i]);
		int m=calc();
		if(m!=-1&&M>m+dx[i]+dy[i])
		{
		   M=m+dx[i]+dy[i];
	   }
		pro(dx[i],dy[i]);
	}
	printf("%d\n",M);
}
int main()
{
	for(int i=0;i<20;i++)
	  scanf("%d",&dir[i]);
	solve();
	return 0;
}