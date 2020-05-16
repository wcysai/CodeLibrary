#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck0
#define y0 fuck1
#define x1 fuck2
#define y1 fuck3
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pr;
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
const int mod=1e9+7;
int T;ll a,b;
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%lld%lld",&a,&b);
        ll ans=0;
        for(;;){
            if(a<0){
                ll tmp=(-a)/b+((-a)%b!=0);
                ans+=tmp;
                a+=tmp*b;
            }else if(a==0)break;
            else{
                ans+=1;
                ll tmp=b;
                b=a;
                a=-tmp;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
