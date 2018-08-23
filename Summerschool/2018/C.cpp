/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-22 13:28:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int T;
ll A,B,C;
int prime[MAXN],phi[MAXN],miu[MAXN],d[MAXN],p2[MAXN],p3[MAXN];
bool is_prime[MAXN];
ull res[MAXN];
vector<int> save;
void sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    phi[1]=miu[1]=p2[1]=p3[1]=1;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; phi[i]=i-1,miu[i]=-1; d[i]=1; p2[i]=1; p3[i]=1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            phi[i*prime[j]]=phi[i]*(i%prime[j]?prime[j]-1:prime[j]);
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            d[i*prime[j]]=i%prime[j]?1:d[i]+1;
            if(i%prime[j]==0)
            {
                p2[i*prime[j]]=(d[i]&1)?p2[i]*prime[j]:p2[i];
                p3[i*prime[j]]=(d[i]%3==0)?p3[i]:p3[i]*prime[j];
                break;
            }
            else 
            {
                p2[i*prime[j]]=p2[i];
                p3[i*prime[j]]=p3[i];
            }
        }
    }
}
int main()
{
    sieve(10000000);
    /*for(int i=1;i<=300;i++)
    {
        int ans=0;
        for(int j=1;j<=100;j++)
        {
            if(j*j*j%i==0) ans++;
        }
        printf("%d %d %d\n",i,ans,100*p3[i]/i);
    }*/
    scanf("%d",&T);
    for(int i=1;i<=10000000;i++) if(miu[i]!=0) save.push_back(i);
    while(T--)
    {
        scanf("%llu%llu%llu",&A,&B,&C);
        for(int i=1;i<=A;i++)
        {
            res[i]=A/i;
            res[i]=res[i]*(B*p2[i]/i);
            res[i]=res[i]*(C*p3[i]/i);
            //printf("%d %lld\n",i,res[i]);
        }
        ull ans=0;
        for(int i=1;i<=A;i++)
        {
            ull tt=0;
            for(int j=0;j<(int)save.size();j++) 
            {
                ll p=save[j]*i;
                if(p>A) break;
                tt+=miu[save[j]]*res[p];
            }
            ans=ans+tt*phi[i];
        }
        printf("%llu\n",ans&((1<<30)-1));
    }
    return 0;
}

