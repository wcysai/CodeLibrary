/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-14 23:35:07
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
int main()
{
    scanf("%d",&n);
    int ans=0;
    a[0]=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1]=1001;
    if(n==1)
    {
        puts("0");
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1]+1&&a[i]==a[i+1]-1) cnt++;
        else {ans=max(ans,cnt); cnt=0;}
    }
    ans=max(ans,cnt);
    printf("%d\n",min(ans,n-1));
    return 0;
}

