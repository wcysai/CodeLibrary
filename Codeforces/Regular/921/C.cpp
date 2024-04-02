#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 999999893
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
void add(int &a,int b){a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b){a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a,b;
        a=pow_mod(2,n/2+1); dec(a,2);
        b=pow_mod(2,(n+1)/2); dec(b,1);
        int x=2LL*(b+1)*(b+1)%MOD;
        int y=1LL*a*a%MOD;
        dec(x,y);
        assert(x!=0);
        printf("%d\n",2LL*a%MOD*pow_mod(x,MOD-2)%MOD);
    }
    return 0;
}

