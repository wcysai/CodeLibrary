/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-15 20:35:08
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int cur[25];
bool check(int x)
{
    memset(cur,0,sizeof(cur));
    for(int k=1;k<=20;k++) cur[k]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>20) continue;
        if(i!=1&&a[i]<=a[i-1]) 
        {
            cur[a[i]]++;
            for(int j=a[i]+1;j<=20;j++) cur[j]=1;
            int now=a[i];
            while(now>=1&&cur[now]>x)
            {
                cur[now]=1;
                now--;
                cur[now]++;
            }
        }
    }
    if(cur[0]>0) return false; else return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    bool f=true;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<=a[i-1]) f=false;
    }
    if(f)
    {
        puts("1");
        return 0;
    }
    int l=1,r=n;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(!check(mid)) l=mid; else r=mid;
    }
    printf("%d\n",r);
    return 0;
}

