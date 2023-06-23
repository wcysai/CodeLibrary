#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string s;
bool isprime[MAXN];
bool good[MAXN];
int pw[MAXN];
int prime[MAXN],phi[MAXN],mu[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; mu[i]=MOD-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            mu[i*prime[j]]=i%prime[j]?MOD-mu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
vector<int> divi[MAXN];
int main()
{
    sieve(100000);
    pw[0]=1;
    for(int i=1;i<=100000;i++) pw[i]=2LL*pw[i-1]%MOD;
    scanf("%d",&n);
    cin>>s;
    int ans=0;
    for(int i=1;i<n;i++){
        if(n%i) continue;
        memset(good,true,sizeof(good));
        int cnt=i;
        for(int j=0;j<n;j++){
            if(s[j]=='.') {
                if(good[j%i]){
                    cnt--;
                    good[j%i]=false;
                }
            }
        }
        for(int j=i;j<n;j+=i){
            if(n%j) continue;
            add(ans,1LL*mu[j/i]*pw[cnt]%MOD);
        }
    }
    printf("%d\n",ans);
    return 0;
}

