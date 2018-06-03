/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-03 19:59:40
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int sum(int x)
{
    int s=0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
int main()
{
    int n;
    scanf("%d",&n);
    int ans=INF;
    for(int i=1;i<=n/2;i++)
        ans=min(ans,sum(i)+sum(n-i));
    printf("%d\n",ans);
    return 0;
}

