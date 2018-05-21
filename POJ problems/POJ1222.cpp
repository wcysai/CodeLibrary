#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};
int tile[5][6];
int flip[5][6];
int opt[5][6];
int n;
int get(int x,int y)
{
	int c=tile[x][y];
	for(int d=0;d<5;d++)
	{
		int x2=x+dx[d],y2=y+dy[d];
		if(0<=x2&&x2<5&&0<=y2&&y2<6)
		  c+=flip[x2][y2];
	}
	return c%2;
}
int calc()
{
	for(int i=1;i<5;i++)
	{
		for(int j=0;j<6;j++)
		  if (get(i-1,j)!=0) 
		    flip[i][j]=1;
	}
	for(int j=0;j<6;j++)
	  if(get(4,j)!=0) return -1;
    int res=0;
    for(int i=0;i<5;i++)
      for(int j=0;j<6;j++)
        res+=flip[i][j];
    return res;
}
void solve()
{
	int res=-1;
	for(int i=0;i<1<<6;i++)
	{
	  memset(flip,0,sizeof(flip));
	  for(int j=0;j<6;j++)
	    flip[0][5-j]=i>>j&1;
	  int num=calc();
	  if(num>=0&&(res<0||res>num))
	  {
	  	res=num;
	  	memcpy(opt,flip,sizeof(flip));
	  }
    }
      for(int i=0;i<5;i++)
        for(int j=0;j<6;j++)
          printf("%d%c",opt[i][j],j==5?'\n':' ');
}
int main()
{
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
	for(int i=0;i<5;i++)
	  for(int j=0;j<6;j++)
	    scanf("%d",&tile[i][j]);
	printf("PUZZLE #%d\n",k);
	solve();
    }
	return 0;
}