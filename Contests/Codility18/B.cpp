/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 18:21:02
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
ll solution(vector<int> &A)
{
    ll ans=0;
    if(A.size()<3) return 0;
    ll d=(ll)A[1]-(ll)A[0],cnt=2;
    for(ll i=2;i<(int)A.size();i++)
    {
        if((ll)A[i]-(ll)A[i-1]==d)
        {
            cnt++;
        }
        else 
        {
            ans=ans+(cnt-1)*(cnt-2)/2;
            if(ans>1000000000) return -1;
            d=(ll)A[i]-(ll)A[i-1];
            cnt=2;
        }
    }
    ans=ans+(cnt-1)*(cnt-2)/2;
    if(ans>1000000000) return -1;
    return ans;
}

