#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int grid[5][5],number[1000000],digit[6],cnt;
void dfs(int x,int y,int z)
{
    if(z==1)
    {
        digit[5]=grid[x][y];
        number[digit[0]*100000+digit[1]*10000+digit[2]*1000+digit[3]*100+digit[4]*10+digit[5]]=1;
    }
    else
    {
      digit[6-z]=grid[x][y];
      if(x>0) dfs(x-1,y,z-1);
      if(y>0) dfs(x,y-1,z-1);
      if(x<4) dfs(x+1,y,z-1);
      if(y<4) dfs(x,y+1,z-1);
    }
   return;
}
int main()
{
    memset(number,0,sizeof(number));
   for(int i=0;i<5;i++)
     for(int j=0;j<5;j++)
       scanf("%d",&grid[i][j]);
   for(int i=0;i<5;i++)
     for(int j=0;j<5;j++)
        dfs(i,j,6);
   cnt=0;
   for(int i=0;i<1000000;i++)
        if(number[i]) cnt++;
   printf("%d",cnt);
   return 0;
}
