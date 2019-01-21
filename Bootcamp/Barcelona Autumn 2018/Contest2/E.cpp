/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 16:48:07
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,x,cnt[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x); if(x!=1) cnt[x]++;
        }
        int ans=0;
        for(int i=300;i>=1;i--)
        {
            if(!cnt[i]) continue;
            if(cnt[i+1]) cnt[i]=0;
            else ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

