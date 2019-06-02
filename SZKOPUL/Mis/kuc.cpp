#include "ckuclib.h"
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,e,a,b,c;
int cur[22];
P dp[22][22];
int tmp[22][22];
void move(int x)
{
    cur[x]++;
    for(int i=0;i<22;i++) tmp[x][i]=INF;
    for(int i=0;i<22;i++)
    {
        tmp[x][i]=min(tmp[x][i],dp[x][i].S+dwa(cur[x]));
        if(i!=21) tmp[x][i]=min(tmp[x][i],dp[x][i+1].F+jedno(cur[x]));
    }
    tmp[x][21]=min(tmp[x][21],dp[x][21].F+jedno(cur[x]));
    if(cur[x]>1)
    {
        int need=(cur[x]+1)/2;
        if(cur[x+1]!=need) move(x+1);
        for(int i=0;i<22;i++) if(i!=0) tmp[x][i]=min(tmp[x][i],dp[x+1][i-1].F+polowa(cur[x]));
    }
    for(int i=0;i<22;i++)
    {
        dp[x][i].S=dp[x][i].F;
        dp[x][i].F=tmp[x][i];
    }
}
int main()
{
    n=dajn(); e=daje();
    if(e>21) e=21;
    for(int i=0;i<22;i++)
    {
        cur[i]=0;
        for(int j=0;j<22;j++) dp[i][j].F=0,dp[i][j].S=INF;
    }
    while(cur[0]!=n) move(0);
    odpowiedz(dp[0][e].F);
    return 0;
}
