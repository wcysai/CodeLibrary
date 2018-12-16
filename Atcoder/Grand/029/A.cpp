/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-15 20:00:53
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
string str;
ll ans;
int main()
{
    cin>>str;
    ll n=str.size();
    ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        if(str[i]=='W') ans+=cnt;
        else cnt++;
    }
    printf("%lld\n",ans);
    return 0;
}

