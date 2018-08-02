/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-02 12:03:57
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
ll n,k,a[MAXN];
int main()
{
    for(ll i=1;i<=40000;i++)
    {
        bool f=false; ll id=-1,id2=-1;
        for(ll j=i*i+1;j<=i*i+2*i;j++)
        {
            if((i*i*i*i)%j==0)
            {
                f=true;id=j-i*i;id2=i*i-(i*i*i*i/j);
                break;
            }
        }
        if(f) printf("%lld %lld %lld\n",i,id,id2);
    }
    return 0;
}

