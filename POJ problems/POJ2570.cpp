#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#define MAXC 26
#define MAXV 205
#define MAXE 1000
#define INF 1000000
using namespace std;
int d[MAXC][MAXV][MAXV];
int V;
char str[MAXC];
void floyd_warshall(int x)
{
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
          for(int j=0;j<V;j++)
            d[x][i][j]|=d[x][i][k]&d[x][k][j];
}
int main()
{
    while(scanf("%d",&V)==1)
    {
        memset(d,0,sizeof(d));
        if(!V) break;
        int x,y;
        while(scanf("%d %d",&x,&y)==2)
        {
            if(!x&&!y) break;
            scanf("%s",str);
            int len=strlen(str);
            for(int i=0;i<len;i++)
               d[str[i]-97][x-1][y-1]=1;
        }
        for(int i=0;i<26;i++)
            floyd_warshall(i);
        while(scanf("%d %d",&x,&y)==2)
        {
            int cnt=0;
            if(!x&&!y) break;
            for(int i=0;i<26;i++)
                if(d[i][x-1][y-1]) printf("%c",97+i),cnt++;
            if(!cnt)  printf("-");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

