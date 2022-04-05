/*************************************************************************
    > File Name: MAGICHF2.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-07 09:34:39
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
ll T,N,K;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&N,&K);
        if(N==2||K==0) {printf("%.10Lf\n",(long double)1.0/N); continue;}
        K--;
        if(N&1) N=(N+1)/2;
        else if(N%4==0) N=N/2;
        else N=N/2+1;
        while(N>1&&K>0)
        {
            N=(N+1)/2;
            K--;
        }
        printf("%.10Lf\n",(long double)1.0/N);
    }
    return 0;
}

