#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int t,n,q,a[2*MAXN];
vector<P> v;
vector<P> upd;
vector<P> qry;
ll ans[MAXN];
void go(int x){
    int cnt=0;
    for(int i=(int)v.size()-1;i>=0;i--){
        P p=v[i];
        if(p.F){
            ll num=1LL*cnt*(n-1)+x;
            upd.push_back(make_pair(p.F-1,num));
            //printf("add %d %lld\n",p.F-1,num);
        }
        cnt+=p.S;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        v.clear(); upd.clear(); qry.clear();
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
        int now=0;
        for(int i=n+2;i>=3;i--){
            now|=a[i];
            if(v.size()&&v.back().F==now) v.back().S++;
            else v.push_back(P(now,1));
        }
        reverse(v.begin(),v.end());
        for(int i=n+2;i<=2*n;i++){
            if(i!=n+2)
            {
                for(auto &p:v) p.F|=a[i];
                v.push_back(P(a[i],1));
                vector<P> tmp;
                for(auto p:v){
                    if(!tmp.size()||tmp.back().F!=p.F) tmp.push_back(p);
                    else tmp.back().S+=p.S;
                }
                swap(v,tmp);
            }
            go(i-n);
            //printf("i=%d\n",i-n);
            //for(auto p:v) printf("(%d %lld) ",p.F,p.S);
            //printf("\n");
        }
        sort(upd.begin(),upd.end());
        vector<P> tmp;
        for(auto x:upd){
            while(tmp.size()&&tmp.back().S>=x.S) tmp.pop_back();
            tmp.push_back(x);
        }
        swap(tmp,upd);
        for(int i=0;i<q;i++) ans[i]=-1;
        for(int i=0;i<q;i++){
            int x;
            scanf("%d",&x);
            if(x<a[1]) {
                ans[i]=1;
                continue;
            }
            else{
                qry.push_back(P(x,i));
            }
        }
        sort(qry.begin(),qry.end());
        now=0;
        for(int i=0;i<(int)upd.size();i++){
            while(now<(int)qry.size()&&qry[now].F<=upd[i].F){
                ans[qry[now].S]=upd[i].S;
                now++;
            }
        }
        for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
    }
    return 0;
}

