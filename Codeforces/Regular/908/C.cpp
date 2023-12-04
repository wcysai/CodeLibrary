#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int t,m,a[MAXN];
int n[MAXN];
ll l[MAXN],r[MAXN],s[MAXN];
vector<P> save[MAXN];
vector<int> occ[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        for(int i=1;i<=m;i++) save[i].clear();
        ll num=0,sum=0;
        for(int i=1;i<=m;i++) {
            scanf("%d%lld%lld",&n[i],&l[i],&r[i]);
            s[i]=0;
            num+=r[i]-l[i]; sum+=l[i];
            vector<ll> tmp;
            for(int j=0;j<n[i];j++){
                ll x;
                scanf("%lld",&x);
                tmp.push_back(x);
            }
            for(int j=0;j<n[i];j++){
                ll x;
                scanf("%lld",&x);
                s[i]+=x;
                save[i].push_back(P(tmp[j],x));
            }
        }
        if(num>100000){
            puts("0"); continue;
        }
        for(int i=1;i<=m;i++){
            ll s=0;
            for(auto p:save[i]){
                if(p.F>=sum&&p.F<=sum+num){
                    occ[p.F-sum].push_back(i);
                }
            }
        }
        ll ans=INF;
        for(int i=0;i<=num;i++){
            ll need=i;
            ll res=0,tmp=num;
            for(auto x:occ[i]){
                tmp-=(r[x]-l[x]);
                ll val=lower_bound(save[x].begin(),save[x].end(),P(sum+i,0))->S;
                //printf("i=%d x=%d val=%lld\n",i,x,val);
                if(s[x]-val>=l[x]){
                    need=max(0LL,need-(s[x]-val-l[x]));
                }
                else{
                    res+=l[x]-(s[x]-val);
                }
            }
            need=max(0LL,need-tmp);
            //printf("i=%d res=%lld need=%lld\n",i,res,need);
            ans=min(ans,res+need);
        }
        printf("%lld\n",ans);
        for(int i=0;i<=num;i++) occ[i].clear();
    }
    return 0;
}

