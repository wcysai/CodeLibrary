#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int maxn=1e7+10;
int f[maxn],nf[maxn],inv[maxn],n,m,ans,L,R;
int C(int x,int y){
    if (y<0||y>x) return 0;
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
int check(int x,int y){
    return x>=y&&x-y<=m;
}
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
int F(int p){
    int ret=0;
    for (int x=L;x<=R;x++) add(ret,C(n,x-p));
    //if (ret>0)cout<<p<<" "<<ret<<" "<<L<<" "<<R<<endl;
    return ret;
}
int main(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    scanf("%d%d",&n,&m); m=(m+1)/2;
    L=-1,R=-1;
    for (int x=0;x<=n;x++){
        if (check(x,n-x)){
            if (L==-1) L=x; R=x;
        }
    }
    ans=F(0);
    int pos,op;
    pos=0; op=0;
    while (1){
        if (!op) pos=-1-pos; else pos=m+1-pos;
        int res=F(pos);
        if (!res) break;
        if (!op) sub(ans,res); else add(ans,res);
        op^=1;
    }
    pos=0; op=0;
    while (1){
        if (!op) pos=m+1-pos; else pos=-1-pos;
        int res=F(pos);
        if (!res) break;
        if (!op) sub(ans,res); else add(ans,res);
        op^=1;
    }
    cout << ans << endl;
}

