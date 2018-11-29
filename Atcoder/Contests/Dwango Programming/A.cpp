/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-29 13:15:52
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
int n,s,now,ans,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    int ans=INF,now=-1;
    for(int i=1;i<=n;i++)
    {
        if(abs(a[i]*n-s)<ans) 
        {
            ans=abs(a[i]*n-s);
            now=i;
        }
    }
    printf("%d\n",now-1);
    return 0;
}

