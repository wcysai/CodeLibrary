#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int prime[MAXN],mu[MAXN];
bool is_prime[MAXN];
ll cnt1[MAXN],cnt2[MAXN],ans;
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; mu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            mu[i*prime[j]]=i%prime[j]?-mu[i]:0;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void add(int x,int val){
    for(int i=1;i*i<=x;i++){
        if(x%i) continue;
        cnt1[i]++; cnt2[i]+=val;
        if(i*i!=x) {cnt1[x/i]++; cnt2[x/i]+=val;}
    }
}
void query(int x,int val){
    ll a=0,b=0;
    for(int i=1;i*i<=x;i++){
        if(x%i) continue;
        a+=mu[i]*cnt1[i]; b+=mu[i]*cnt2[i];
        if(i*i!=x) {a+=mu[x/i]*cnt1[x/i]; b+=mu[x/i]*cnt2[x/i];}
    }
    ans+=a*(val-1); ans-=b;
}
int main()
{
    sieve(300000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ans=0;
    for(int i=1;i<=n;i++){
        query(a[i],i);
        add(a[i],i);
    }
    printf("%lld\n",ans);
    return 0;
}

