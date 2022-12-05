#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int maxn=1e6+10;
int f[maxn],nf[maxn],inv[maxn];
int C(int x,int y){
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}

int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    int T; scanf("%d",&T);
    while (T--){
        int n,m;scanf("%d%d",&n,&m);
        int ans=1ll*f[n]*C(n-1,m-1)%M;
        printf("%d\n",ans);
    }
}