/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-09 16:00:47
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
bool is_prime[MAXN];
int prime[MAXN];
int pow_mod(int a,int i,int m)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    int p=sieve(100000);
    int gmax=0;
    vector<P> ans;
    for(int i=0;i<p;i++)
    {
        if(i%100==0) printf("%d\n",i);
        //printf("%d: ",prime[i]);
        int res=0,save=-1;
        for(int j=1;j<prime[i]-1;j++)
        {
            for(int k=1;;k++)
            {
                if(k>res)
                {
                    res=k;
                    save=j;
                }
                if(pow_mod(k,j,prime[i])!=1) break;
            }
        }
        if(res>gmax)
        {
            printf("%d %d\n",prime[i],save);
            gmax=res;
        }
        //printf("%d %d\n",res,save);
    }
    return 0;
}

