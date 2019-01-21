/*************************************************************************
    > File Name: I.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 20:17:02
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
int n;
int cnt[MAXN];
int main()
{
    for(int i=1;i<=100000;i++)
    {
        int s=i,cur=i;
        while(s<=100000)
        {
            cnt[s]++;
            cur++;
            s+=cur;
        }
    }
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i) continue;
        if(i*i==n) ans+=cnt[i]*cnt[i];
        else ans+=2*cnt[i]*cnt[n/i];
    }
    printf("%d\n",ans);
    return 0;
}

