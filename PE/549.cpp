#include<bits/stdc++.h>
#define MAXN 100000000
#define MAXP 5800005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
int id[MAXN];
int cntid[MAXP][30];
int res[MAXP];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
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
    int p=sieve(100000000);
    for(int i=0;i<p;i++)
        id[prime[i]]=i;
    memset(res,0,sizeof(res));
    for(int i=2;i<=100000000;i++)
    {
        int t=i;
        for(int j=0;j<p;j++)
        {
            if(is_prime[t]) {res[id[t]]++; if(res[id[t]]<30) cntid[id[t]][res[id[t]]]=i; break;}
            if(t==1) break;
            while(t%prime[j]==0) {res[j]++; if(res[j]<30) cntid[j][res[j]]=i; t=t/prime[j];}
        }
    }
    ll ans=0;
    for(int i=2;i<=100000000;i++)
    {
        int t=i;
        ll res=-INF;
        for(int j=0;j<p;j++)
        {
            if(is_prime[t]) {res=max(res,(ll)cntid[id[t]][1]); break;}
            if(t==1) break;
            int cnt=0;
            while(t%prime[j]==0) {cnt++; t=t/prime[j];}
            if(cnt) res=max(res,(ll)cntid[j][cnt]);
        }
        //printf("%d %d\n",i,res);
        ans+=res;
    }
    printf("%I64d\n",ans);
    return 0;
}