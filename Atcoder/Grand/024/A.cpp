/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-23 14:11:50
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
ll a,b,c,k;
int main()
{
    scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
    ll res=a-b;
    printf("%lld\n",res*((k&1)?-1:1));
    return 0;
}

