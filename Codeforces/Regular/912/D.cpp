#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k,a[MAXN];
ll res[MAXN];
vector<pair<ll,int> > qry;
ll ans[MAXN];
vector<ll> solve(int now,vector<int> &v){
    if(now==0||!v.size()){
        vector<ll> ret(1<<now);
        return ret;
    }
    vector<ll> ret(1<<now);
    vector<int> one,zero;
    for(auto x:v){
        if(x&(1<<(now-1))) one.push_back(x-(1<<(now-1))); else zero.push_back(x);
    }
    ll sum=0;
    for(auto x:zero) sum+=(1<<(now-1))-x;
    int sz0=(int)zero.size(),sz1=(int)one.size();
    vector<ll> ret1=solve(now-1,zero);
    vector<ll> ret2=solve(now-1,one);
    for(int i=0;i<(1<<(now-1));i++) ret[i]=ret1[i]+ret2[i];
    for(int i=0;i<(1<<(now-1));i++) ret[i+(1<<(now-1))]=ret2[i]+sum+1LL*i*sz0;
    return ret;
}
int main(){
    scanf("%d%d",&n,&q);
    ll sum=0;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); sum+=a[i];}
    vector<int> tmp;
    for(int i=1;i<=n;i++) tmp.push_back(a[i]);
    vector<ll> cont=solve(20,tmp);
    for(int i=1;i<=q;i++){
        ll k;
        scanf("%lld",&k);
        qry.push_back(make_pair(k,i));
    }
    sort(qry.begin(),qry.end());
    vector<int> maxi(q+1,0);
    for(int i=0;i<(1<<20);i++){
        //printf("%d %lld\n",i,cont[i]);
        int id=lower_bound(qry.begin(),qry.end(),make_pair(cont[i],0))-qry.begin()+1;
        if(id<=q) maxi[id]=max(maxi[id],i);
    }
    for(int i=1;i<=q;i++) {maxi[i]=max(maxi[i],maxi[i-1]); ans[qry[i-1].S]=maxi[i];}
    for(int i=0;i<q;i++){
        if(qry[i].F>=1LL*n*(1<<20)-sum){
            ll rem=qry[i].F-(1LL*n*(1<<20)-sum);
            ans[qry[i].S]=(1<<20)+rem/n;
        }
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}

