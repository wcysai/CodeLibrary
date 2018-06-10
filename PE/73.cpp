/*************************************************************************
    > File Name: 73.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 09:03:32
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
int n,k,a[MAXN];
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
bool check(int x,int y)
{
    return 3*x>y&&2*x<y;
}
int main()
{
    int cnt=0;
    for(int i=2;i<=12000;i++)
        for(int j=1;j<i;j++)
            if(gcd(i,j)==1&&check(j,i)) cnt++;
    printf("%d\n",cnt);
    return 0;
}

