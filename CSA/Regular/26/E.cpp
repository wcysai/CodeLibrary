/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-15 20:30:34
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
int n,m,k;
P a[MAXN];
int b[MAXN],l[MAXN],r[MAXN],dp[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++) scanf("%d%d",&a[i].F,&a[i].S);
    sort(a,a+k);
    vector<int> v;
    for(int i=0;i<k;i++)
        v.push_back(a[i].S);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<k;i++)
        b[i]=lower_bound(v.begin(),v.end(),a[i].S)-v.begin()+1;
    fill(dp,dp+k,INF);
    for(int i=0;i<k;i++)
    {
        *upper_bound(dp,dp+k,b[i])=b[i];
        l[i]=upper_bound(dp,dp+k,b[i])-dp;
    }
    int len=lower_bound(dp,dp+k,INF)-dp;
    //printf("%d\n",len);
    for(int i=0;i<k;i++) b[i]=-b[i];
    fill(dp,dp+k,INF);
    for(int i=k-1;i>=0;i--)
    {
        *upper_bound(dp,dp+k,b[i])=b[i];
        r[i]=upper_bound(dp,dp+k,b[i])-dp;
    }
    //for(int i=0;i<k;i++) printf("%d ",b[i]); puts("");
    //for(int i=0;i<k;i++) printf("%d %d\n",l[i],r[i]);
    for(int i=0;i<k;i++) if(l[i]+r[i]-1==len) cnt[l[i]]++;
    int ans=0;
    for(int i=0;i<=100000;i++)
        if(cnt[i]==1) ans++;
    printf("%d\n",ans);
    return 0;
}

