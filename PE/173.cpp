/*************************************************************************
    > File Name: 173.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-13 17:27:21
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
ll ans=0;
int main()
{
    for(ll d=2;d<=1000;d+=2)
        ans+=(1000000-d*d)/(2*d);
    printf("%lld\n",ans);
    return 0;
}

