#include<bits/stdc++.h>
#define int long long
#define MAXN 15
#define INF 1000000000
#define INF2 1000000000000000000LL
#define MOD 1000000007
#define M1 (1<<9)
#define M2 1953125
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,k,a[MAXN],xx,yy,q,mod;
vector<int> res1[(1<<9)];
vector<int> res2[2000000];
ll pow_mod(int a,ll i,int m){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
ll r[MAXN][MAXN],x[MAXN];
int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int mod_inverse(int a,int m){
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll solve(vector<P> &v){
    int n=v.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            r[i][j]=mod_inverse(v[i].S,v[j].S);
    ll ans=0;
    for(int i=0;i<n;i++){
        x[i]=v[i].F;
        for(int j=0;j<i;j++){
            x[i]=r[j][i]*(x[i]-x[j]);
            x[i]=x[i]%v[i].S;
            if(x[i]<0) x[i]+=v[i].S;
        }
    }
    int base=1;
    for(int i=0;i<n;i++){
        ans+=1LL*base*x[i];
        base*=v[i].S;
    }
    return ans%INF;
}
signed main(){
    //printf("%lld\n",pow_mod(893943543,893943543,INF));
    int z=INF/(1<<9);
    xx=(1<<9),yy=INF/(1<<9)*4;
    for(int i=0;i<M1;i++){
        res1[pow_mod(i,i,M1)].push_back(i);
    }
    for(int i=0;i<M2;i++){
        if(i%5==0) continue;
        int t=pow_mod(i,i,M2);
        res2[t].push_back(i);
        int magic=1;
        if(i%5==2) magic=280182;
        else if(i%5==3) magic=1672943;
        else if(i%5==4) magic=1953124;
            for(int j=1;j<=3;j++){
                t=1LL*t*magic%M2;
                res2[t].push_back(i+j*M2);
                //assert(pow_mod(i+j*M2,i+j*M2,M2)==t);
            }
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&mod);
        int modx=mod%xx,mody=mod%(yy/4);
        if(!res1[modx].size()||!res2[mody].size()) {puts("-1"); continue;}
        ll ans=INF2;
        for(auto a:res1[modx])
            for(auto b:res2[mody]){
                if(b%2==0) continue;
                vector<P> v;
                v.push_back(make_pair(a,xx)); v.push_back(make_pair(b%(yy/4),yy/4));
                ll res=solve(v);
                while(res%yy!=b&&res<=10LL*INF) res+=INF;
                if(res%yy==b) ans=min(ans,res);
            }
        if(ans==INF2) puts("-1"); else printf("%lld\n",ans);
    }
    return 0;
}

