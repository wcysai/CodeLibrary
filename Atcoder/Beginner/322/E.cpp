#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000000000000LL
#define MOD 1000000007
#define MAXM (6*6*6*6*6)
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,p,a[MAXN][6],c[MAXN];
ll dp[MAXM],ndp[MAXM];
void upd(ll &a,ll b) {a=min(a,b);}
int encode(vector<int> &v){
    int res=0;
    for(int i=0;i<(int)v.size();i++){
        res*=(p+1);
        res+=v[i];
    }
    return res;
}
vector<int> decode(int x){
    vector<int> v;
    for(int i=0;i<k;i++){
        v.push_back(x%(p+1));
        x/=(p+1);
    }
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=k;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1;i<MAXM;i++) dp[i]=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<MAXM;j++) ndp[j]=INF;
        for(int j=0;j<MAXM;j++){
            if(dp[j]==INF) continue;
            upd(ndp[j],dp[j]);
            vector<int> v=decode(j);
            for(int q=0;q<k;q++) v[q]=min(p,v[q]+a[i+1][q+1]);
            int to=encode(v);
            upd(ndp[to],dp[j]+c[i+1]);
        }
        swap(dp,ndp);
    }
    int need=0;
    for(int i=0;i<k;i++) need=need*(p+1)+p;
    printf("%lld\n",dp[need]==INF?-1:dp[need]);
    return 0;
}

