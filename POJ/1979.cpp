#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int w,h,x,y,cnt,i,j;
char mat[20][20];
void dfs(int m,int n)
{
    mat[m][n]='#';
    cnt++;
    if(m!=h-1&&mat[m+1][n]!='#') dfs(m+1,n);
    if(n!=w-1&&mat[m][n+1]!='#') dfs(m,n+1);
    if(m!=0&&mat[m-1][n]!='#') dfs(m-1,n);
    if(n!=0&&mat[m][n-1]!='#') dfs(m,n-1);
    return;
}
int main()
{
    scanf("%d %d",&w,&h);
    while(w!=0&&h!=0)
{
    for(i=0;i<h;i++)
    {
          scanf("%s",&mat[i]);
          for(j=0;j<w;j++)
          if(mat[i][j]=='@')
          {
              x=i;
              y=j;
          }
    }
cnt=0;
dfs(x,y);
printf("%d\n",cnt);
 scanf("%d %d",&w,&h);
}
return 0;
}