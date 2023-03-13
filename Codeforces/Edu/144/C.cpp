#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int cnt[MAXN],ways[MAXN],sum[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    ways[1]=1;
    for(int i=1;i<=1000000;i++){
        int z=1; cnt[i]=1;
        while(z*2<=i) z*=2,cnt[i]++;
        if(i>=2)
        {
            ways[i]=0;
            for(int j=2;j<=i;j++){
                if(cnt[i/j]+1==cnt[i]) add(ways[i],ways[i/j]);
                else break;
            }
        }
    }
    for(int i=1;i<=1000000;i++){
        sum[i]=sum[i-1];
        add(sum[i],ways[i]);
    }
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d%d",&l,&r);
        int val=cnt[r/l],ans=0;
        for(int i=1,c;i<=r;i=c+1){
            c=r/(r/i);
            if(cnt[r/i]==val){
                int lb=max(i,l);
                if(lb<=c){
                    add(ans,1LL*(c-lb+1)*ways[r/i]%MOD);
                }
            }
        }
        printf("%d %d\n",val,ans);
    }
    return 0;
}

