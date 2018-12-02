/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-29 18:01:43
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,n;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        ll x=sqrt(n);
        while(x*x<n) x++;
        if(x*x>n) puts("0"); else puts("1");
    }
    return 0;
}

