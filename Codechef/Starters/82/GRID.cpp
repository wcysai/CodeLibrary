#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k;
P p[MAXN];
ll pre[MAXN],suf[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].F,&p[i].S);
        if(k==1) {printf("%d\n",0); continue;}
        sort(p+1,p+n+1);
        ll ans=INF;
        for(int i=1;i<=n;i++){
            priority_queue<ll> pque;
            ll sum=0;
            for(int j=1;j<=n;j++){
                ll x=1LL*max(p[j].S-p[i].S,p[i].S-p[j].S)-p[j].F;
                sum+=x;
                pque.push(x);
                if(pque.size()>k/2) {sum-=pque.top(); pque.pop();}
                pre[j]=sum;
            }
            sum=0;
            while(pque.size()) pque.pop();
            for(int j=n;j>=1;j--){
                ll x=1LL*max(p[j].S-p[i].S,p[i].S-p[j].S)+p[j].F;
                sum+=x;
                pque.push(x);
                if(pque.size()>k/2) {sum-=pque.top(); pque.pop();}
                suf[j]=sum;
            }
            if(k%2==0){
                for(int j=k/2;n-j>=k/2;j++) ans=min(ans,pre[j]+suf[j+1]);
            }
            else{
                for(int j=k/2+1;n-j>=k/2;j++) ans=min(ans,pre[j-1]+suf[j+1]+1LL*max(p[j].S-p[i].S,p[i].S-p[j].S));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
