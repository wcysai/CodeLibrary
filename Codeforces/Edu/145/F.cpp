#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int t,n,k,a[2*MAXN],b[2*MAXN];
ll sum[2*MAXN];
int nxtone[2*MAXN];
P nxt[MAXLOGN][2*MAXN];
ll calc(int s,int t){
    ll ans=0; int cur=s;
    for(int i=19;i>=0;i--){
        if(nxt[i][cur].S<=t){
            ans+=nxt[i][cur].F;
            cur=nxt[i][cur].S;
        }
    }
    if(cur<t){
        ans+=b[cur]*(sum[t-1]-sum[cur-1]);
    }
    return ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) {a[i+n]=a[i]; b[i+n]=b[i];}
        for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
        nxtone[2*n+1]=2*n+1;
        for(int i=2*n;i>=1;i--) if(b[i]==1) nxtone[i]=i; else nxtone[i]=nxtone[i+1];
        for(int i=1;i<=2*n;i++){
            if(b[i]==2){
                nxt[0][i]=P(2*a[i],i+1);
            }
            else{
                int pos=nxtone[i+1];
                if(pos==2*n+1||sum[pos-1]-sum[i-1]>k){//reach farthest
                    int l=i,r=2*n+1;
                    while(r-l>1){
                        int mid=(l+r)/2;
                        if(sum[mid-1]-sum[i-1]<=k) l=mid; else r=mid;
                    }
                    if(l==2*n) nxt[0][i]=P((sum[l-1]-sum[i-1]),l);
                    else nxt[0][i]=P(2LL*(sum[l]-sum[i-1])-k,l+1);
                }
                else{
                    nxt[0][i]=P(sum[pos-1]-sum[i-1],pos);
                }
            }
            //printf("i=%d F=%lld S=%d\n",i,nxt[0][i].F,nxt[0][i].S);
        }
        for(int i=1;i<=19;i++){
            for(int j=1;j<=2*n;j++){
                if(nxt[i-1][j].S==2*n+1) nxt[i][j]=nxt[i-1][j];
                else{
                    int pos=nxt[i-1][j].S;
                    ll s=nxt[i-1][j].F+nxt[i-1][pos].F;
                    nxt[i][j]=P(s,nxt[i-1][pos].S);
                }
            }
        }
        for(int i=1;i<=n;i++) printf("%lld ",calc(i,i+n));
        printf("\n");
    }
    return 0;
}

