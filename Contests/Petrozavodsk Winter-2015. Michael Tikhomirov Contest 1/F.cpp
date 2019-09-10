#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int inv[MAXN],E[MAXN],Esum[MAXN],Esum2[MAXN],E2[MAXN],Eprod[MAXN];
int main()
{
    inv[1]=1;
    for(int i=2;i<=1000000;i++) inv[i]=MOD-1LL*(MOD/i)*inv[MOD%i]%MOD;
    E[0]=E2[0]=Esum[0]=Esum2[0]=1; Eprod[0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        E[i]=2LL*Esum[i-1]%MOD*inv[i]%MOD;
        Esum[i]=Esum[i-1]; add(Esum[i],E[i]);
        E2[i]=1LL*(2*i+2)*Esum2[i-1]%MOD*inv[i]%MOD*inv[i]%MOD;  add(E2[i],4LL*Eprod[i-1]*inv[i]%MOD*inv[i]%MOD);
        Esum2[i]=Esum2[i-1]; add(Esum2[i],E2[i]);
        Eprod[i]=Eprod[i-1]; add(Eprod[i],2LL*Esum2[i-1]*inv[i]%MOD); add(Eprod[i],4LL*Eprod[i-1]*inv[i]%MOD);
        //printf("i=%d E[i]=%d Esum[i]=%d E2[i]=%d Esum2[i]=%d Eprod[i]=%d\n",i,E[i],Esum[i],E2[i],Esum2[i],Eprod[i]);
    }
    int ans=E2[n];
    dec(ans,1LL*E[n]*E[n]%MOD);
    printf("%d\n",ans);
    return 0;
}
