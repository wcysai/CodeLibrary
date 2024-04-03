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
typedef double db;
int n,k,a[MAXN];
int prime[MAXN],mu[MAXN],cf[MAXN];
int w[MAXN];
db prob[MAXN];
bool is_prime[MAXN];
int sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(is_prime[i]) {prime[p++]=i; mu[i]=-1;}
        for(int j=0;j<p;j++){
            if(prime[j]*i>n) break;
            mu[i*prime[j]]=i%prime[j]?-mu[i]:0;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main(){
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++) {scanf("%d",&w[i]); sum+=w[i];}
    sieve(100000);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            cf[i]+=mu[j/i];
            prob[j]+=w[i];
        }
    }
    for(int i=1;i<=n;i++) prob[i]/=sum;
    db ans=0;
    for(int i=1;i<=n;i++){
        ans+=1.0*cf[i]*prob[i]/(1-prob[i]);
    }
    printf("%.10f\n",ans);
    return 0;
}

