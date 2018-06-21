/*************************************************************************
    > File Name: 619.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-21 00:00:50
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
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
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
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
map<int,int> mp;
bool used[MAXN];
int main()
{
    int p=sieve(1234567);
    //for(int i=0;i<p;i++) printf("%d\n",prime[i]);
    for(int i=0;i<p;i++) mp[prime[i]]=i;
    memset(used,false,sizeof(used));
    int cnt=0;
    for(int i=1000000;i<=1234567;i++)
    {
        printf("%d\n",i);
        int t=i;
        for(int j=0;j<p;j++)
        {
            if(is_prime[t])
            {
                if(!used[mp[t]]) cnt++;
                used[mp[t]]=true;
                break;
            }
            //printf("%d\n",t);
            if(t%prime[j]==0)
            {
                while(t%prime[j]==0) 
                    t=t/prime[j];
                //printf("%d\n",t);
                if(!used[j]) cnt++;
                used[j]=true;
            }
            if(t==1) break;
        }
    }
    printf("%d\n",pow_mod(2,234568-cnt)-1);
    return 0;
}

