#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MAXN 2015
using namespace std;
char cow[MAXN];
bool judge(int x,int y)
{
    if (cow[x]!=cow[y]) return cow[x]<cow[y];
    if(x==y||x==y-1) return true;
    return judge(x+1,y-1);
}
int main()
{
  int n;
  char input[MAXN];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%s",&input);
    cow[i]=input[0];
  }
  int x=0,y=n-1,cnt=0;
  while(x<=y)
  {
      if(judge(x,y))
      {
          printf("%c",cow[x]);
          x++;
      }
      else
      {
          printf("%c",cow[y]);
          y--;
      }
      cnt++;
      if(cnt==80)
      {
          printf("\n");
          cnt=0;
      }
  }
}