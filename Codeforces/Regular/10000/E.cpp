#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define INV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int solve(int now,vector<int> &v){
    if(!v.size()) return 0;
    if(now==-1){
        int sz=(int)v.size();
        return 1LL*sz*sz%MOD;
    }
    vector<int> zero,one;
    for(auto x:v){
        if(!(x&(1<<now))) zero.push_back(x); else one.push_back(x);
    }
    int sz0=(int)zero.size(),sz1=(int)one.size();
    int ans=0;
    add(ans,3LL*sz0*sz1%MOD);
    add(ans,1LL*sz1*sz1%MOD);
    add(ans,solve(now-1,zero)); add(ans,solve(now-1,one));
    return ans;
}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> v;
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        int ans=solve(29,v);
        int inv=pow_mod(n,MOD-2);
        ans=1LL*ans*inv%MOD*inv%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

