#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 2017
using namespace std;
int a[MAXN],b[MAXN],adj[MAXN],sum[MAXN],save,cnt1,cnt2,n;
int check(int x,int y)
{
    int s=0;
    if(x>=0)
    {
        s=x/y;
        if((s+1)*y-x<x-s*y) return s+1; else return s;
    }
    if(x<0)
    {
        s=(-x)/y;
        if((s+1)*y+x<-x-s+y) return -s-1; else return -s;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    b[0]=a[0];
    adj[0]=0;
    cnt1=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<b[i-1])
        {
            b[i]=b[i-1];
            adj[i]=b[i]-a[i];
        }
        else
        {
            b[i]=a[i];
            adj[i]=0;
        }
    }
    save=0;
    sum[n]=0;
    for(int i=n-1;i>=0;i--)
        sum[i]=adj[i]+sum[i+1];
    int p=check(sum[0],n);
    for(int j=0;j<n;j++)
        b[j]-=p;
    save-=p;
    for(int i=1;i<n;i++)
    {
        if(b[i]>b[i-1]&&sum[i]-save>0)
        {
            int x=min(b[i]-b[i-1],check(sum[i]+save*(n-i),n-i));
            if(x!=0)
            {
            save-=x;
            for(int j=i;j<n;j++)
                b[j]-=x;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=max(a[i]-b[i],b[i]-a[i]);
    memset(b,0,sizeof(b));
    memset(sum,0,sizeof(sum));
     memset(adj,0,sizeof(adj));
    b[0]=a[0];
    adj[0]=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>b[i-1])
        {
            b[i]=b[i-1];
            adj[i]=b[i]-a[i];
        }
        else
        {
            b[i]=a[i];
            adj[i]=0;
        }
    }
    save=0;
    sum[n]=0;
    for(int i=n-1;i>=0;i--)
        sum[i]=adj[i]+sum[i+1];
    p=check(sum[0],n);
    for(int j=0;j<n;j++)
        b[j]-=p;
    save-=p;
    for(int i=1;i<n;i++)
    {
        if(b[i]>b[i-1]&&sum[i]-save>0)
        {
            int x=min(b[i]-b[i-1],check(sum[i]+save*(n-i),n-i));
            if(x!=0)
            {
            save-=x;
            for(int j=i;j<n;j++)
                b[j]-=x;
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
        res+=max(a[i]-b[i],b[i]-a[i]);
    ans=min(ans,res);
    printf("%d\n",ans);
    return 0;
}
