/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-23 22:55:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);a[x]++;
    }
    int ans=1;
    for(int i=2;i<=2000000;i++)
    {
        if(!a[i]) continue;
        if(i==2&&a[i]>2) ans=1LL*ans*6%MOD;
        else if(i==3&&a[i]>27) ans=1LL*ans*81%MOD;
        else if(i==5&&a[i]>3125) ans=1LL*ans*15625%MOD;
        else ans=1LL*ans*a[i]%MOD*i%MOD;
    }
    printf("%d\n",ans);
    return 0;
}

