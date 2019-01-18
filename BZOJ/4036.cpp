#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n;
db p[(1<<20)];
db dp[(1<<20)];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++) {scanf("%Lf",&p[i]); dp[i]=p[i];}
    for(int i=0;i<n;i++)
    {
        bool f=false;
        for(int j=1;j<(1<<n);j++)
        {
            if(!(j&(1<<i))) continue;
            if(p[j]) {f=true; break;} 
        }
        if(!f) {puts("INF"); return 0;}
    }
    db ans=0;
    for(int i=0;i<n;i++)
        for(int mask=0;mask<(1<<n);mask++)
            if(mask&(1<<i)) dp[mask]+=dp[mask^(1<<i)];
    //for(int mask=0;mask<(1<<n);mask++) printf("%d %Lf\n",mask,dp[mask]);
    for(int mask=1;mask<(1<<n);mask++)
    {
        int cnt=0;
        for(int i=0;i<n;i++) if(mask&(1<<i)) cnt++;
        if(cnt&1) ans+=1.0/(1-dp[(1<<n)-1-mask]); else ans-=1.0/(1-dp[(1<<n)-1-mask]);
    }
    printf("%.10Lf\n",ans);
    return 0;
}

