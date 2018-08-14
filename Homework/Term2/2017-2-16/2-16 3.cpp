#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MAXN 22
#define MAXM 80
using namespace std;
char world[MAXN][MAXM];
bool change[MAXN][MAXM];
int n;
int calc(int n,int m)
{
    int s=0,i,j;
    for(int di=-1;di<=1;di++)
        for(int dj=-1;dj<=1;dj++)
    {
        if(di!=0||dj!=0)
        {
            i=n+di;
            j=m+dj;
            if(i==-1) i=MAXN-1;
            if(j==-1) j=MAXM-1;
            if(i==MAXN) i=0;
            if(j==MAXM) j=0;
            if (world[i][j]=='*') s++;
        }
    }
    return s;
}
int main()
{
    cin>>n;
    char c;
    c=getchar();
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXM;j++)
          world[i][j]=getchar();
        c=getchar();
    }
    for(int k=0;k<n;k++)
    {
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXM;j++)
        {
            if(world[i][j]=='*')
        {
            int s=calc(i,j);
            if((s==2)||(s==3)) change[i][j]=false; else change[i][j]=true;
        }
        else
        {
            int s=calc(i,j);
            if(s==3) change[i][j]=true; else change[i][j]=false;
        }
        }
    }
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXM;j++)
        {
            if(world[i][j]=='*'&&change[i][j]) world[i][j]=' ';
            else if(world[i][j]==' '&&change[i][j]) world[i][j]='*';
        }
    }
    }
    for(int i=0;i<MAXN-1;i++)
    {
        for(int j=0;j<MAXM;j++)
            printf("%c",world[i][j]);
        printf("\n");
    }
    for(int j=0;j<MAXM;j++)
        printf("%c",world[MAXN-1][j]);
    return 0;
}
