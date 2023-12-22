#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
ll a[MAXN];
int ans[MAXN];
int pre[MAXN],suf[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll s=0;
        vector<pair<ll,int> > now;
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld",&a[i]); 
            now.push_back(make_pair(a[i],i));
        }
        for(int i=1;i<=n;i++) ans[i]=0;
        for(int i=60;i>=-1;i--){
            if(i==-1){
                for(auto x:now) ans[x.S]=1; 
                break;
            }
            vector<int> tmp;
            for(int j=0;j<(int)now.size();j++) if(now[j].F&(1LL<<i)) tmp.push_back(j);
            if(tmp.size()&1){
                for(int j=0;j<(int)tmp.size();j+=2) ans[now[tmp[j]].S]=1;
                break;
            }
            else{
                if(!tmp.size()) continue;
                ll s=0;
                for(auto x:now) s^=x.F;
                int cnt=0; ll ss=0;
                for(int j=1;j<=(int)tmp.size();j++) pre[j]=suf[j]=0;
                for(int j=0;j<(int)now.size();j++){
                    ss^=now[j].F;
                    if(now[j].F&(1LL<<i)) cnt++;
                    if(cnt&1){
                        if(ss>=(s^ss)) pre[cnt]=1;
                        if((s^ss)>=ss) suf[cnt+1]=1;
                    }
                }
                for(int j=(int)tmp.size()-2;j>=1;j--) if(pre[j+2]) pre[j]=1;
                for(int j=3;j<=(int)tmp.size();j++) if(suf[j-2]) suf[j]=1;
                for(int j=1;j<=(int)tmp.size();j++) if(pre[j]||suf[j]) ans[now[tmp[j-1]].S]=1;
                vector<pair<ll,int> > dummy;
                for(int k=0;k<tmp[0];k++) dummy.push_back(now[k]);
                for(int j=0;j<(int)tmp.size();j+=2){
                    ll ss=0;
                    for(int k=tmp[j];k<=tmp[j+1];k++) ss^=now[k].F;
                    dummy.push_back(make_pair(ss,0));
                    int nxt=(j==(int)tmp.size()-2?(int)now.size():tmp[j+2]);
                    for(int k=tmp[j+1]+1;k<nxt;k++) dummy.push_back(now[k]);
                }
                swap(dummy,now);
            }
        }
        for(int i=1;i<=n;i++) printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}

