/*************************************************************************
    > File Name: 25D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-09 15:52:51
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
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    int l=n+1,r=0,cnt=0,ans=0;
    for(int i=n;i>=1;i--,cnt++)
    {
        l=min(l,a[i]);r=max(r,a[i]);
        ans=max(ans,r-l+min(2,n)-cnt);
    }
    printf("%d\n",ans);
    return 0;
}

