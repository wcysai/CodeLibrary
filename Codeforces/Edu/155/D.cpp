#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0,res=0;
    for(int i=1;i<=n;i++) a[i]^=a[i-1];
    for(int i=0;i<30;i++){
        int cnt0=1,sum0=0,cnt1=0,sum1=0;
        for(int r=1;r<=n;r++){
            if(a[r]&(1<<i)){
                int cont=(1LL*r*cnt0-sum0+MOD)%MOD;
                add(res,1LL*(1<<i)*cont%MOD);
                add(cnt1,1); add(sum1,r);
            }
            else{
                int cont=(1LL*r*cnt1-sum1+MOD)%MOD;
                add(res,1LL*(1<<i)*cont%MOD);
                add(cnt0,1); add(sum0,r);
            }
        }
    }
    printf("%d\n",res);
    return 0;
}

