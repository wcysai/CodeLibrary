#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,h[MAXN],L[MAXN],R[MAXN];
int st[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    int t=0;
    for(int i=1;i<=n;i++){
        while(t>0&&h[st[t-1]]<h[i]) t--;
        L[i]=t==0?0:st[t-1];
        st[t++]=i;
    }
    t=0;
    for(int i=n;i>=1;i--){
        while(t>0&&h[st[t-1]]<h[i]) t--;
        R[i]=t==0?n+1:st[t-1];
        st[t++]=i;
    }
    ll p=0,q=1;
    for(int i=1;i<=n;i++){
        if(L[i]){
            ll nq=h[L[i]]-h[L[i]+1],np=1LL*(i-L[i]-1)*nq+h[i]-h[L[i]+1];
            ll g=gcd(np,nq);
            np/=g; nq/=g;
            if(np*q>p*nq) {p=np; q=nq;}
        }
        if(R[i]!=n+1){
            ll nq=h[R[i]]-h[R[i]-1],np=1LL*(R[i]-i-1)*nq+h[i]-h[R[i]-1];
            ll g=gcd(np,nq);
            np/=g; nq/=g;
            if(np*q>p*nq) {p=np; q=nq;}
        }
    }
    if(q==1) printf("%lld\n",p); else printf("%lld/%lld\n",p,q);
    return 0;
}

