#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<snkueue>
#define MAXN 20
using namespace std;
int field[MAXN][MAXN];
int save[4];
int n,m;
bool check()
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt=0;
        for(int j=0;j<m;j++)
            if(field[i][j]!=j+1) cnt++;
        if(cnt!=0&&cnt!=2) return false;
    }
    return true;
}
void exc(int x,int y)
{
    int t;
    for(int i=0;i<n;i++)
    {
        t=field[i][x];
        field[i][x]=field[i][y];
        field[i][y]=t;
    }
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          scanf("%d",&field[i][j]);
    int s=0,k=0;
    while(true)
    {
        s=0;
    for(int i=0;i<m;i++)
    {
        if(field[k][i]!=i+1)
        {
            if(s<4) save[s]=i;
            s++;
        }
    }
    if(s!=0) break;
    k++;
    if(k==n) break;
    }
    if(k==n)
    {
        printf("YES");
        return 0;
    }
    if(s>4)
    {
        printf("NO");
        return 0;
    }
    bool f=0;
    if(s==2)
    {
        if(check()) f=1;
         exc(save[0],save[1]);
         if(check()) f=1;
    }
    if(s==3)
    {
        if(check()) f=1;
        exc(save[0],save[1]);
        if(check()) f=1;
        exc(save[0],save[1]);
       exc(save[0],save[2]);
        if(check()) f=1;
        exc(save[0],save[2]);
        exc(save[1],save[2]);
        if(check()) f=1;
        exc(save[1],save[2]);
    }
    if(s==4)
    {
         if(check()) f=1;
        exc(save[0],save[1]);
        if(check()) f=1;
        exc(save[0],save[1]);
       exc(save[0],save[2]);
        if(check()) f=1;
        exc(save[0],save[2]);
        exc(save[1],save[2]);
        if(check()) f=1;
        exc(save[1],save[2]);
         exc(save[0],save[3]);
        if(check()) f=1;
        exc(save[0],save[3]);
         exc(save[1],save[3]);
        if(check()) f=1;
        exc(save[1],save[3]);
         exc(save[2],save[3]);
        if(check()) f=1;
        exc(save[2],save[3]);
    }
    if(f) printf("YES"); else printf("NO");
    return 0;
}
