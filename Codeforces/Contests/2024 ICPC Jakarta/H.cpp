#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+3;
const int M=998244353;
int a[26],b[26];
char s[maxn];
int n,m,f[maxn],nf[maxn],inv[maxn];
int dp[26][maxn],sum[maxn],ans;
void init(){
    inv[1]=1; for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    f[0]=nf[0]=1; for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
}
int C(int x,int y){
    if (y<0||y>x) return 0;
    return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
int main(){
    init();
    cin >> n >> m;
    cin >> s; for (int i=0;i<n;i++) a[s[i]-'A']++;
    cin >> s; for (int i=0;i<m;i++) b[s[i]-'A']++;
    sum[0]=1;
    for (int i=25;i>=0;i--){
        for (int j=0;j<=min(a[i],b[i]);j++) dp[i][b[i]-j]=1ll*C(a[i],j)*sum[a[i]-j]%M;
        sum[n]=dp[i][n]; for (int j=n-1;j>=0;j--) sum[j]=(sum[j+1]+dp[i][j])%M;
    }
    ans=sum[0];
    for (int i=0;i<26;i++) ans=1ll*ans*nf[a[i]]%M;
    ans=1ll*ans*f[n]%M;
    cout << ans << endl;
}
