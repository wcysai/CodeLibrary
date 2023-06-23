#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000005
#define MAXT 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int prime[1000005],num[MAXN];
bool is_prime[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int ans[MAXN];
vector<P> query;
//Alice (0) Bob (0,1) Alice (0,1,2),...
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    num[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; num[i]=1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            num[prime[j]*i]=num[i]+1;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    int p=sieve(10000000);
    for(int i=1;i<=10000000;i++){
        //as alice
        int round=2*((num[i]+1)/2+1)-1+2*(num[i]/2+1);
        for(int j=2*i;j<=10000000;j+=i){
            add(ans[j],round);
        }
    }
    for(int i=1;i<=10000000;i++) add(ans[i],ans[i-1]); 
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        int cnt=0;
        for(int j=1,r;j<=n;j=r+1){
		    r=n/(n/j);
		    add(cnt,1LL*(n/j)*(r-j+1)%MOD);
	    }   
        dec(cnt,n);
        cnt=2LL*cnt%MOD;
        int res=1LL*ans[n]*pow_mod(cnt,MOD-2)%MOD;
        printf("%d\n",res);
    }
    return 0;
}

