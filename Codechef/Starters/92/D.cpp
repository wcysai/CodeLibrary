#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,K,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
signed main()
{
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&N,&K);
        for(int i=1;i<=N;i++) scanf("%lld",&a[i]);
        sort(a+1,a+N+1);
        int cur=a[1];
        for(int i=1;i<=N-1;i++){
            int d=a[i+1]-cur;
            ll need=1LL*d*i;
            if(need<=K){
                K-=need;
                cur=a[i+1];
            }
            else{
                cur+=K/i;
                K%=i;
                for(int j=1;j<=i;j++) a[j]=(cur%MOD);
                for(int j=1;j<=K;j++) add(a[j],1);
                K=-1; 
                break;
            }
        }
        if(K>=0){
            cur+=K/N;
            K%=N;
            for(int j=1;j<=N;j++) a[j]=(cur%MOD);
            for(int j=1;j<=K;j++) add(a[j],1);
        }
        int sum=0,ans=0;
        for(int i=1;i<=N;i++) 
        {
            add(ans,1LL*sum*a[i]%MOD);
            add(sum,a[i]);
        }
        printf("%d\n",ans%MOD);
    }
    return 0;
}

