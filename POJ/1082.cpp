#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<assert.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXN 100005
using namespace std;
int n,t;
int leap_year[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int not_leap_year[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int dp[2005][13][32];
bool leap(int y)
{
    if(y%400==0) return true;
    if(y%100==0) return false;
    if(y%4==0) return true;
}
bool valid(int y,int m,int d)
{
    if(leap(y)) return leap_year[m-1]>=d;
    return not_leap_year[m-1]>=d;
}
int judge(int y,int m,int d)
{
    if(dp[y][m][d]!=-1) return dp[y][m][d];
    if(y>2001) return dp[y][m][d]=1;
    if(y==2001)
    {
        if(m>11) return dp[y][m][d]=1;
        if(m==11)
        {
            if(d>4) return dp[y][m][d]=1;
            if (d==4) return dp[y][m][d]=0;
        }
    }
    int yy=y,mm=m,dd=d;
    dd=dd+1;
    if(leap(yy))
    {
        if(dd>leap_year[mm-1]) {dd-=leap_year[mm-1]; mm++;}
        if(mm>12) {mm-=12; yy++;}
    }
    else
    {
        if(dd>not_leap_year[mm-1]) {dd-=leap_year[mm-1]; mm++;}
        if(mm>12) {mm-=12; yy++;}
    }
    int f1=judge(yy,mm,dd);
    yy=y,mm=m,dd=d;
    mm=mm+1;
    if(mm>12) {mm-=12; yy++;}
    if(!valid(yy,mm,dd)) return dp[y][m][d]=1-f1;
    else
    {
        int f2=judge(yy,mm,dd);
        return dp[y][m][d]=(1-f1)|(1-f2);
    }
}
int main()
{
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    int x,y,z;
    for(int i=2001;i>=1900;i--)
        judge(i,1,1);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(judge(x,y,z)) puts("YES"); else puts("NO");
    }
    return 0;
}
