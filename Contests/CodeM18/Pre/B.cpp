/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 14:13:19
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,x,y,ans,t;
int main()
{
    int ans=-INF,t=-1;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        if(x*m+y*(n-m)>=ans)
        {
            ans=x*m+y*(n-m);
            t=i;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(i==t) printf("%d",n); else printf("0");
        if(i==k-1) printf("\n"); else printf(" ");
    }
    return 0;
}

