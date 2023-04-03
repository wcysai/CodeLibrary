#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 8000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,q,n,k,a[MAXN];
//(n,a,b): h\in [(n-2)(a-b)+a+1,(n-1)(a-b)+a]
ll calc(ll h,ll a,ll b){
    if(h<=a) return 1;
    return (h-a+(a-b-1))/(a-b)+1;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&q);
        ll l=1,r=INF;
        for(int i=0;i<q;i++){
            int type,a,b,n;
            scanf("%d",&type);
            if(type==1){
                scanf("%d%d%d",&a,&b,&n);
                ll lb=(n==1?1:1LL*(n-2)*(a-b)+a+1),rb=1LL*(n-1)*(a-b)+a;
                if(max(l,lb)>min(r,rb)){
                    printf("0 ");
                }
                else{
                    printf("1 ");
                    l=max(l,lb); r=min(r,rb);
                }
            }
            else{
                scanf("%d%d",&a,&b);
                if(r==INF) printf("-1 ");
                else{
                    ll x=calc(l,a,b),y=calc(r,a,b);
                    if(x!=y) printf("-1 "); else printf("%lld ",x);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

