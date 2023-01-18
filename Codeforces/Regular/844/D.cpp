#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool issqr(ll x){
    int t=(int)(sqrt(x));
    for(int i=max(0,t-2);i<=t+2;i++) if(1LL*t*t==x) return true;
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                int d=a[j]-a[i];
                //(x+dif)^2-x^2=d
                for(int dif=1;dif*dif<=d;dif++){
                    if((d-dif*dif)%(2*dif)) continue;
                    int x=(d-dif*dif)/(2*dif);
                    if(1LL*x*x<a[i]) continue;
                    ll inc=1LL*x*x-a[i];
                    int cnt=0;
                    for(int k=1;k<=n;k++) if(issqr(a[k]+inc)) cnt++;
                    ans=max(ans,cnt);
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}

