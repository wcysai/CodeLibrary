/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-23 14:29:52
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],x;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[x]=i;
    }
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i==1||a[i]>=a[i-1]) cnt++;
        else
        {
            ans=max(ans,cnt);
            cnt=1;
        }
    }
    ans=max(ans,cnt);
    printf("%d\n",n-ans);
    return 0;
}

