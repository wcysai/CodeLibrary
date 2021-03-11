#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int maxn=5005;
int f[maxn],nf[maxn],inv[maxn],a[maxn][2],n,p,ways[maxn][maxn];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
int C(int x,int y){
	if (y<0||y>x) return 0;
	return 1ll*f[x]*nf[y]%M*nf[x-y]%M;
}
int calc(int x,int y){
	if (x==0) return y==0;
	return C(y-1,x-1);
}
void init(){
    f[0]=nf[0]=inv[1]=1;
    for (int i=2;i<maxn;i++) inv[i]=M-1ll*(M/i)*inv[M%i]%M;
    for (int i=1;i<maxn;i++) f[i]=1ll*f[i-1]*i%M,nf[i]=1ll*nf[i-1]*inv[i]%M;
    for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++){
			ways[i][j]=calc(i,j);
			if (j>=p) add(ways[i][j],ways[i][j-p]);
		}
}
int main(){
	cin >> n >> p;
    init();
	if (p==2){
        cout << (bool)(n==1) << endl;
        return 0;
	}
    a[0][0]=1;
	for (int i=1;i<=n;i++){
        add(a[i][0],a[i-1][1]);
        add(a[i][1],1ll*(p-2)*a[i-1][1]%M);
        add(a[i][1],1ll*(p-1)*a[i-1][0]%M);
	}
	int ans=a[n][1];
    int tot=0;
    for (int i=0;i+p<=n;i++){
		int ret=0;
		int sum=n-i-p;
		for (int j=0;j<=i&&j*(p-2)<=sum;j++){
			int res=0;
            if (j&1){
				sub(res,C(sum-j*(p-2),i));
				add(res,ways[i][sum-j*(p-2)]);
            } else {
				add(res,C(sum-j*(p-2),i));
				sub(res,ways[i][sum-j*(p-2)]);
            }
			add(ret,1ll*res*C(i,j)%M);
		}
		add(tot,1ll*ret*C(n,i)%M);
    }
    cout<<tot<<endl;
	tot=1ll*tot*(p-1)%M;
	sub(ans,tot);
	cout << ans << endl;
	return 0;
}