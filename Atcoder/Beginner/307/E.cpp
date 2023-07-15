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
int n,m;
int f[MAXN],g[MAXN];//f: not same g:  same 
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d",&n,&m);
    f[2]=1LL*m*(m-1)%MOD; g[2]=0;
    for(int i=3;i<=n;i++){
        f[i]=1LL*f[i-1]*(m-2)%MOD;
        add(f[i],1LL*g[i-1]*(m-1)%MOD);
        g[i]=f[i-1];
    }
    printf("%d\n",f[n]);
    return 0;
}

