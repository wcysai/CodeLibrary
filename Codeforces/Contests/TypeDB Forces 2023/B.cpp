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
int t,n,p;
int prime[MAXN];
bool is_prime[MAXN];
vector<P> fact;
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
void factorize(int n){
    fact.clear();
    for(int i=0;i<p;i++){
        if(n%prime[i]==0){
            int cnt=0;
            while(n%prime[i]==0) {cnt++; n/=prime[i];}
            fact.push_back(P(cnt,prime[i]));
        }
    }
    if(n>1) fact.push_back(P(1,n));
    sort(fact.begin(),fact.end(),greater<P>());
}
int main()
{
    p=sieve(40000);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        factorize(n);
        int prod=1,ans=0;
        for(int i=0;i<(int)fact.size();i++){
            prod=prod*fact[i].S;
            if(i==(int)fact.size()-1){
                ans+=prod*fact[i].F;
            }
            else ans+=prod*(fact[i].F-fact[i+1].F);
        }
        printf("%d\n",ans);
    }
    return 0;
}

