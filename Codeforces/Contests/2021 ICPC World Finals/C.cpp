#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 3000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll m;
int main(){
    scanf("%d%lld",&n,&m);
    int limit;
    for(int i=2;;i++){
        ll prod=1;
        bool f=true;
        for(int j=1;j<=n-1;j++){
            if(INF/i<=prod){
                f=false;
                break;
            }
            prod*=i;
            if(prod>m) {f=false; break;}
        }
        if(!f) {limit=i-1; break;}
    }
    //printf("limit=%d\n",limit);
    ll ansp=INF,ansq=INF;
    for(int q=1;q<=limit;q++){
        vector<ll> prod(n);
        prod[0]=1;
        for(int j=1;j<=n-1;j++) prod[j]=prod[j-1]*q;
        //printf("q=%d\n",q);
        for(int d=1;d<q;d++){
            ll sum=0,cur=1;
            bool f=true;
            for(int j=0;j<=n-1;j++){
                if((m-sum)/cur<prod[n-1-j]) {f=false; break;}
                sum+=prod[n-1-j]*cur;
                if(sum>m) {f=false; break;}
                cur*=d;
            }
            if(f&&m%sum==0){
                ansp=q-d; ansq=q;
                break;
            }
        }
        if(ansp!=INF) break;
    }
    if(ansq==INF) puts("impossible"); else printf("%lld %lld\n",ansp,ansq);
    return 0;
}

