/*************************************************************************
    > File Name: find.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-12 09:47:18
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN];
string xx,yy;
int calc(int x,int y)
{
    return !(x&y);
}
int main()
{
    cin>>xx;cin>>yy;
    n=(int)yy.size();m=(int)xx.size();
    for(int i=0;i<m;i++) a[0][i+1]=xx[i]-'0';
    for(int i=0;i<n;i++) a[i+1][0]=yy[i]-'0';
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=calc(a[i-1][j],a[i][j-1]);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}

