/*************************************************************************
    > File Name: E2.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-10 00:01:19
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
int n,m,a[MAXN],s[MAXN],z[MAXN];
int bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    int ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]>m) a[i]=0; else if(a[i]<m) a[i]=-1; else a[i]=0;
    }
    for(int i=1;i<=n;i++) 
    {
        s[i]=a[i]+s[i-1];
        if(a[i]==0) z[i]=z[i-1]+1; else z[i]=z[i-1];
    }
    for(int i=0;i<=n;i++)
    {
        ans+=s.count(sum[i]-z[i]);ans+=s.count(sum[i]-z[i]+1);
        s.insert(sum[i]-z[i]);
    }
    printf("%d\n",ans);
    int last=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            s.clear();
            for(int j=last;j<i;j++)
            {
                ans-=s.count(sum[i]);ans-=s.count(sum[i]+1);
                s.insert(sum[i]);
            }
            last=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}

