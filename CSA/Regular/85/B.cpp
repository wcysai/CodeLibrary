/*************************************************************************
    > File Name: 85B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 23:07:59
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
int n,x;
int main()
{
    scanf("%d%d",&n,&x);
    int cnt=0;
    while(n%10==0) {n=n/10;cnt++;}
    while(x>=10-n%10)
    {
        x-=10-n%10;
        n+=10-n%10;
        while(n%10==0)
        {
            n=n/10;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

