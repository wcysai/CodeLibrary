#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
  int pack[7];
  int cnt;
  scanf("%d %d %d %d %d %d",&pack[1],&pack[2],&pack[3],&pack[4],&pack[5],&pack[6]);
  while(pack[1]!=0||pack[2]!=0||pack[3]!=0||pack[4]!=0||pack[5]!=0||pack[6]!=0)
  {
    cnt=0;
  cnt+=pack[6];
  cnt+=pack[5];
  pack[1]-=11*pack[5];
  cnt+=pack[4];
  if(pack[2]>=5*pack[4]) pack[2]-=pack[4]*5;
  else
  {
    pack[1]-=20*pack[4]-4*pack[2];
    pack[2]=0;
  }
  if(pack[3]>0)
  {
  cnt+=(pack[3]-1)/4+1;
  if(pack[3]%4!=0)
  {
      if(pack[2]>=(7-2*(pack[3]%4)))
      {
        pack[1]-=8-(pack[3]%4);
        pack[2]-=7-2*(pack[3]%4);
      }
      else
      {
          pack[1]-=36-9*(pack[3]%4)-4*pack[2];
          pack[2]=0;
      }
  }
  }
  if(pack[2]>0)
  {
      cnt+=(pack[2]-1)/9+1;
      pack[1]-=36-(pack[2]%9)*4;
  }
  if(pack[1]>0)
    cnt+=(pack[1]-1)/36+1;
  printf("%d\n",cnt);
  scanf("%d %d %d %d %d %d",&pack[1],&pack[2],&pack[3],&pack[4],&pack[5],&pack[6]);
  }
  return 0;
}