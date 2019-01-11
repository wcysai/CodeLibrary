#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll T,M,A,B;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(ll i=0;i<(int)A.size();i++)
        for(ll k=0;k<(int)B.size();k++)
            for(ll j=0;j<(int)B[0].size();j++)
                C[i][j]=(C[i][j]+1LL*A[i][k]*B[k][j])%M;
    return C;
}
mat pow_mod(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(ll i=0;i<(int)A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
mat fib(2,vec(2)),invfib(2,vec(2));
mat init(2,vec(1)),id(2,vec(1));
map<P,ll> mp;
int main()
{
    fib[0][0]=0;fib[0][1]=fib[1][0]=fib[1][1]=1;
    invfib[0][1]=invfib[1][0]=1;invfib[1][1]=0;
    id[0][0]=0; id[1][0]=1;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&M,&A,&B); mp.clear();
        invfib[0][0]=M-1;
        init[0][0]=A; init[1][0]=B;
        ll t=(int)sqrt(6*M);
        mat fibt=pow_mod(invfib,t);
        mat cur(2,vec(2)); cur[0][0]=cur[1][1]=1; cur[0][1]=cur[1][0]=0;
        for(ll i=0;i<t;i++)
        {
            mat res=mul(cur,id);
            P ret=P(res[0][0],res[1][0]);
            //printf("%lld %lld\n",ret.F,ret.S);
            if(mp.find(ret)==mp.end()) mp[ret]=i;
            cur=mul(cur,fib);
        }
        cur[0][0]=cur[1][1]=1; cur[0][1]=cur[1][0]=0;
        for(ll i=0;;i++)
        {
            mat res=mul(cur,init);
            P ret=P(res[0][0],res[1][0]);
            //printf("%lld %lld\n",ret.F,ret.S);
            if(mp.find(ret)!=mp.end()) {printf("%lld\n",i*t+mp[ret]); break;}
            cur=mul(cur,fibt);
            if(i*t>=6*M) {puts("-1"); break;}
        }
    }
    return 0;
}

