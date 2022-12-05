#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1000000007;
int C[20][20];
int dp[42][20][200];
int k;
ll n,m;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
int solve(int d,int c,int w){
    if (w<0||w>90) return 0;
    if (d==-1) return (w==0);
    int &ret=dp[d][c][w];
    if (ret!=-1) return ret;
    ret=0; int o=(m>>d)&1; w=w*2+((n>>d)&1);
    if (!o){
        for (int j=0;j<=k-c;j++){
            int cof=C[k-c][j];
            add(ret,1ll*cof*solve(d-1,c,w-j*(k-j))%M);
        }
    } else {
        for (int i=0;i<=c;i++)
        for (int j=0;j<=k-c;j++){
            int cof=1ll*C[c][i]*C[k-c][j]%M;
            add(ret,1ll*cof*solve(d-1,i,w-(i+j)*(k-i-j))%M);
        }
    }
    return ret;
}
int main(){
    cin >> n >> m >> k;
    for (int i=0;i<=k;i++){
        C[i][0]=C[i][i]=1;
        for (int j=1;j<i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    memset(dp,-1,sizeof(dp));
    ll w=n>>40;
    if (w>81){cout << 0 << endl;return 0;}
    cout << solve(39,k,w) << endl;
}