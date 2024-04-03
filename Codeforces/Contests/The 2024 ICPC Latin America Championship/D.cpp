#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
ll n;
int p,prime[MAXN];
bool is_prime[MAXN];
int sieve(int n){
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
vector<P> fact;
void factorize(ll x){
    for(int i=0;i<p;i++){
        if(x%prime[i]==0){
            int cnt=0;
            while(x%prime[i]==0){
                cnt++;
                x/=prime[i];
            }
            fact.push_back(P(prime[i],cnt));
        }
    }
    if(x>1) fact.push_back(P(x,1));
}
int main(){
    p=sieve(1000000);
    scanf("%lld",&n);
    if(n==1) {puts("N"); return 0;}
    factorize(n);
    //(auto p:fact) printf("%lld %d\n",p.F,p.S);
    if(fact.size()==1){
        if(fact[0].S&1) puts("Y"); else puts("N");
    }
    else{
        if(fact.size()==2&&fact[0].S==1&&fact[1].S==1) puts("Y"); else puts("N");
    }
    return 0;
}

