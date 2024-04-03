#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,g[MAXN],r[MAXN];
int dp[2*MAXN],ndp1[2*MAXN],ndp2[2*MAXN];
int main(){
    scanf("%d",&n);
    int res=0,s=0;
    vector<int> v;
    bool zero=false;
    for(int i=1;i<=n;i++) {scanf("%d%d",&g[i],&r[i]); s+=g[i]; if(!g[i]) zero=true; v.push_back(g[i]); res=gcd(res,r[i]);}
    sort(v.begin(),v.end());
    vector<P> items;
    for(int i=0;i<(int)v.size();i++){
        if(items.size()&&items.back().F==v[i]) items.back().S++;
        else items.push_back(P(v[i],1));
    }
    for(int i=0;i<=2*s;i++) dp[i]=INF;
    dp[s]=0;
    for(auto p:items){
        for(int i=0;i<=2*s;i++) ndp1[i]=ndp2[i]=INF;
        if(p.S&1){
            for(int j=0;j<=2*s;j++){
                if(j>=p.F&&dp[j-p.F]!=INF) ndp1[j]=0;
                else if(j>=2*p.F&&ndp1[j-2*p.F]<p.S/2) ndp1[j]=ndp1[j-2*p.F]+1;
            }
            for(int j=2*s;j>=0;j--){
                if(j+p.F<=2*s&&dp[j+p.F]!=INF) ndp2[j]=0;
                else if(j+2*p.F<=2*s&&ndp2[j+2*p.F]<p.S/2) ndp2[j]=ndp2[j+2*p.F]+1;
            }
        }
        else{
            for(int j=0;j<=2*s;j++){
                if(dp[j]!=INF) ndp1[j]=0;
                else if(j>=2*p.F&&ndp1[j-2*p.F]<p.S/2) ndp1[j]=ndp1[j-2*p.F]+1;
            }
            for(int j=2*s;j>=0;j--){
                if(dp[j]!=INF) ndp2[j]=0;
                else if(j+2*p.F<=2*s&&ndp2[j+2*p.F]<p.S/2) ndp2[j]=ndp2[j+2*p.F]+1;
            }
        }
        for(int i=0;i<=2*s;i++) if(ndp1[i]!=INF||ndp2[i]!=INF) {dp[i]=0; } else dp[i]=INF;
    }
    bool f=false;
    for(int i=0;i<(zero?s+1:s);i+=res) if(i+s<=2*s&&dp[i+s]!=INF) f=true;
    if(f) puts("Y"); else puts("N");
    return 0;
}

