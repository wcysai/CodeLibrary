#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],k[MAXN];
ll sum[MAXN];
int ans[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&k[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    set<P> s;
    set<pair<int,P> > events;
    for(int i=1;i<=n;i++){
        s.insert(P(i,i));
        if(i<n) events.insert(make_pair(a[i]-1,P(i,i)));
    }
    int len=1;
    for(int i=m;i>=1;i--){
        while(events.size()&&(--events.end())->F>=k[i]){
            P p=(--events.end())->S;
            events.erase(--events.end());
            if(!s.count(p)) continue;
            auto it=s.upper_bound(p);
            //it++;
            P q=*it;
            //printf("i=%d pF=%d pS=%d qF=%d qS=%d\n",i,p.F,p.S,q.F,q.S);
            s.erase(p); s.erase(q); s.insert(P(p.F,q.S));
            len=max(len,q.S-p.F+1);
            if(q.S!=n){
                ll ss=sum[q.S]-sum[p.F-1];
                int newk=(ss-1)/(q.S-p.F+1);
                events.insert(make_pair(newk,P(p.F,q.S)));
            }
        }
        ans[i]=len-1;
    }
    for(int i=1;i<=m;i++) printf("%d%c",ans[i],i==m?'\n':' ');
    return 0;
}

