#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=2e6+10;
const int M=998244353;
int kase=0;
int n,lst[maxn],dp[maxn],a[maxn];
int P[maxn];
char s[maxn];
string S;
void manacher(){
    int R=0,mid=0;
    for (int i=0;i<(int)S.size();i++) P[i]=0;
    for (int i=1;i<(int)S.size()-1;i++){
        P[i]=(R>i)?min(P[2*mid-1],R-i):1;
        while (S[i+P[i]]==S[i-P[i]]) P[i]++;
        if (i+P[i]>R){
            R=i+P[i];
            mid=i;
        }
    }
}
void upd(int x,int y){
    x=max(x,1);
    while (x<=n) a[x]=min(a[x],y),x+=x&(-x);
}
int qry(int x){
    int ret=inf;
    while (x) ret=min(ret,a[x]),x-=x&(-x);
    return ret;
}
void solve(){
    cin >> n >> s+1; S="@";
    for (int i=1;i<n;i++) S+=s[i],S+="#"; 
    S+=s[n]; S+="!";
    manacher();
    /*
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j+=2){
            f[i][j]=1;
            for (int p=i,q=j;p<q;p++,q--) f[i][j]&=(s[p]==s[q]);
        }
    ll a1=0;
    for (int i=1;i<=n;i++){
        memset(g,0,sizeof(g));
        for (int j=i+1;j<=n;j+=2){
            g[j]=f[i][j];
            for (int k=i+1;k<j;k+=2) g[j]|=g[k]&&f[k+1][j];
            if (g[j]) ++a1;
        }
    }
    cout << a1 << endl;
    */
    ll ans=0;
    for (int i=0;i<=n+1;i++) a[i]=inf,dp[i]=0;
    for (int i=n-1;i>=1;i--){
        int r=P[i*2]/2;
        upd(i-r+1,i*2+1);
        int j=qry(i);
        if (j<inf){
            dp[i]=dp[j-i+1]+1;
            ans+=dp[i];
        }
    }
    cout << ans << endl;
    for (int i=0;i<S.size();i++) P[i]=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}

