#include<bits/stdc++.h>
#define MAXN 2500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void in(int &x){
    int ff=1;char c=getchar();x=0;
    while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
    while(c<='9'&&c>='0'){ x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    x*=ff;
}
int fact[MAXN],invf[MAXN],save[MAXN];
int d,a[2][MAXN];
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=2500000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[2500000]=pow_mod(fact[2500000],MOD-2);
    for(int i=2499999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    in(d);
    for(int i=0;i<2;i++)
        for(int j=0;j<=d;j++) in(a[i][j]);
    int ad=0,amd=0,bmd=0;
    for(int i=0;i<=d;i++){
        if((d-i)&1) dec(ad,1LL*a[0][i]*invf[i]%MOD*invf[d-i]%MOD);
        else add(ad,1LL*a[0][i]*invf[i]%MOD*invf[d-i]%MOD);
    }
    for(int i=0;i<=d;i++) {
        int sum=(1LL*d*(d+1)/2-i)%MOD;
        save[i]=1LL*invf[i]%MOD*invf[d-i]%MOD*sum%MOD;
    }
    for(int i=0;i<=d;i++){
        int sum=(1LL*d*(d+1)/2-i)%MOD;
        if((d-i)&1) add(amd,1LL*a[0][i]*save[i]%MOD);
        else dec(amd,1LL*a[0][i]*save[i]%MOD);
    }
    for(int i=0;i<=d;i++){
        int sum=(1LL*d*(d+1)/2-i)%MOD;
        if((d-i)&1) add(bmd,1LL*a[1][i]*save[i]%MOD);
        else dec(bmd,1LL*a[1][i]*save[i]%MOD);
    }
    //printf("ad=%d amd=%d bmd=%d\n",ad,amd,bmd);
    ad=1LL*ad*d%MOD; bmd-=amd; if(bmd<0) bmd+=MOD;
    bmd=1LL*bmd*pow_mod(ad,MOD-2)%MOD;
    printf("%d\n",bmd);
    return 0;
}

