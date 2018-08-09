/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-09 14:38:49
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
    while(scanf("%d",&n)==1)
    {
        int ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            int minx=INF,maxx=-INF,cnt=0;
            for(int j=0;j<n;j++) if(i&(1<<j)) cnt++;
            if(cnt<2) continue;
            for(int j=0;j<n;j++)
                for(int k=j+1;k<n;k++)
                    if((i&(1<<j))&&(i&(1<<k))) 
                    {
                        minx=min(minx,k-j);
                        maxx=max(maxx,k-j);
                    }
            ans+=minx*maxx;
        }
        printf("%d\n",ans);
    }
    return 0;
}

