/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-14 23:45:28
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
    int ans=1,mx=0,minx=INF;
    int p=sieve(1000000);
    scanf("%d",&n);
    for(int i=0;i<p;i++)
    {
        int cnt=0;
        if(n%prime[i]==0) ans=ans*prime[i];
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            cnt++;
        }
        mx=max(mx,cnt);
        if(cnt) minx=min(minx,cnt);
    }
    if(mx==1||mx==0) printf("%d 0\n",ans);
    else
    {
        int res=0;
        bool f=false;
        int i;
        for(i=1;i<mx;i=i*2);
        if(i==mx) f=true;
        if(f&&(mx==minx)) res--; 
        while(i>1) i=i/2,res++;
        printf("%d %d\n",ans,res+1);
    }
    return 0;
}

