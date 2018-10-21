/*************************************************************************
    > File Name: BITOBYT.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-07 03:32:12
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
ll x,y,z;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        x=y=z=0;
        scanf("%d",&n);n--;
        int t=n/26;n-=t*26;
        x=1LL<<t;
        if(n>=10) {z=x; x=0;}
        else if(n>=2) {y=x; x=0;}
        printf("%lld %lld %lld\n",x,y,z);
    }
    return 0;
}

