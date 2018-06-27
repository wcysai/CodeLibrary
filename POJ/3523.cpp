#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<deque>
#define MAXN 20
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
char puzzle[MAXN][MAXN];
int w,h,n,ans,perm[3];
P a[3],b[3],ta[3];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int manhattan(P x, P y)
{
    return max(x.F-y.F,y.F-x.F)+max(x.S-y.S,y.S-x.S);
}
int dfs(int dep)
{
    int res=0;
    for(int i=0;i<n;i++)
        res=max(res,manhattan(ta[i],b[i]));
    if(dep+res>ans) return false;
    bool f=true;
    for(int i=0;i<n;i++)
        if(ta[i]!=b[i]) f=false;
    if(f) return true;
    for(int i=0;i<n;i++)
        perm[i]=i;
    do
    {
        for(int i=0;i<n;i++)
        {
            int x=ta[perm[i]].F,y=ta[perm[i]].S;
            for(int j=0;j<4;j++)
            {
                bool flag=true;
                int nx=x+dx[j],ny=y+dx[y];
                for(int k=0;k<n;k++)
                    if(nx==ta[k].F&&ny==)
            }
        }
    }while(next_permutation(perm));
}
int main()
{
    while(scanf("%d%d%d",&w,&h,&n)==3)
    {
        if(!w&&!h&&!n) break;
        for(int i=0;i<h;i++)
            scanf("%s",&puzzle[i]);
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                if(puzzle[i][j]=='a') {ta[0]=a[0].F=i;ta[0]=a[0].S=j;}
                if(puzzle[i][j]=='b') {ta[1]=a[1].F=i;ta[1]=a[1].S=j;}
                if(puzzle[i][j]=='c') {ta[2]=a[2].F=i;ta[2]=a[2].S=j;}
                if(puzzle[i][j]=='A') {b[0].F=i;b[0].S=j;}
                if(puzzle[i][j]=='B') {b[1].F=i;b[1].S=j;}
                if(puzzle[i][j]=='C') {b[2].F=i;b[2].S=j;}
            }
        for(ans=0;!dfs(0);ans++)
            for(int i=0;i<n;i++)
                ta[i]=a[i];
    }
}
