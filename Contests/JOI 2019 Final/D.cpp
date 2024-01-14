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
int n,x[MAXN],y[MAXN],cnt[2][MAXN];
int main(){
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=2*n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        int nx,ny;
        if(y[i]<=1) ny=1; else ny=2;
        if(x[i]>=1&&x[i]<=n) nx=x[i]; else if(x[i]<1) nx=1; else nx=n;
        cnt[ny-1][nx]++;
        ans+=max(x[i]-nx,nx-x[i])+max(y[i]-ny,ny-y[i]);
    }
    int s1=0,s2=0;
    for(int i=1;i<=n;i++){
        s1+=(cnt[0][i]-1);
        s2+=(cnt[1][i]-1);
        if(s1>0&&s2<0){
            int t=min(s1,-s2);
            ans+=t;
            s1-=t; s2+=t;
        }
        else if(s1<0&&s2>0){
            int t=min(-s1,s2);
            ans+=t;
            s1+=t; s2-=t;
        }
        ans+=max(-s1,s1); ans+=max(-s2,s2);
    }
    printf("%lld\n",ans);
    return 0;
}

