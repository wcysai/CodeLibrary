#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
ll x[MAXN],w[MAXN];
ll sum[MAXN];
ll premax[MAXN],premin[MAXN];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=q;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=q;i++) sum[i]=sum[i-1]+w[i];
    premax[0]=-INF; premin[0]=INF;
    for(int i=1;i<=q;i++) premax[i]=max(premax[i-1],sum[i]);
    for(int i=1;i<=q;i++) premin[i]=min(premin[i-1],sum[i]);
    for(int i=1;i<=n;i++){
        ll ans=0;
        if(i==1) ans+=max(0LL,-premin[q]);
        else{
            if(x[i]-max(0LL,-premin[q])>=x[i-1]+max(0LL,premax[q])) ans+=max(0LL,-premin[q]);
            else{
                int l=0,r=q;
                while(r-l>1){
                    int mid=(l+r)/2;
                    if(x[i]-max(0LL,-premin[mid])>=x[i-1]+max(0LL,premax[mid])) l=mid;
                    else r=mid;
                }
                if(max(0LL,premax[l+1])>max(0LL,premax[l])) ans+=max(0LL,-premin[l]);
                else ans+=x[i]-x[i-1]-max(0LL,premax[l]);
            }
        }
        if(i==n) ans+=max(0LL,premax[q]);
        else{
            if(x[i+1]-max(0LL,-premin[q])>=x[i]+max(0LL,premax[q])) ans+=max(0LL,premax[q]);
            else{
                int l=0,r=q;
                while(r-l>1){
                    int mid=(l+r)/2;
                    if(x[i+1]-max(0LL,-premin[mid])>=x[i]+max(0LL,premax[mid])) l=mid;
                    else r=mid;
                }
                if(max(0LL,-premin[l+1])>max(0LL,-premin[l])) ans+=max(0LL,premax[l]);
                else ans+=x[i+1]-x[i]-max(0LL,-premin[l]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

