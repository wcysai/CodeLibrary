/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-10 08:56:59
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXK 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
long double dp[MAXN][MAXK];
int p[MAXN][MAXK];
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}
long double solve(int i,int j)
{
    if(j==0) return (long double) i-1;
    if(i>n) return (long double) n+solve(1,j);
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=(p[j][i]*solve(i+1,j)+(100-p[j][i])*solve(i+1,j-1))/100;
}
int main()
{
    in(k);in(n);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            in(p[i][j]);
    for(int i=1;i<=n+1;i++) dp[i][0]=i-1;
    for(int i=1;i<=k;i++)
    {
        long double l=1,r=1e8;
        while(r-l>1e-6)
        {
            long double mid=(l+r)/2;
            dp[1][i]=mid;
            for(int j=2;j<=n;j++) dp[j][i]=-1;
            for(int j=n;j>=2;j--) solve(j,i);
            if(dp[1][i]*100<(p[i][1]*dp[2][i]+(100-p[i][1])*dp[2][i-1])) l=mid; else r=mid;
        }
    } 
    printf("%.10Lf\n",dp[1][k]);
    return 0;
}

