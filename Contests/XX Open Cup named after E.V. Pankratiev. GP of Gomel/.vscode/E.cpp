#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,x;
int p[MAXN],q[MAXN];
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
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d%d%d",&n,&k,&x);
    for(int i=0;i<=k;i++)
    {
        cin>>str;
        p[i]=(str[2]-'0')*1000+(str[3]-'0')*100+(str[4]-'0')*10+(str[5]-'0');
        p[i]=1LL*p[i]*pow_mod(10000,MOD-2)%MOD;
    }
    q[0]=pow_mod(p[0],n);
    int s=q[0],ans=0;
    for(int i=1;i<=x-1;i++)
    {
        int sum=0;
        for(int j=1;j<=min(k,i);j++) add(sum,1LL*j*q[i-j]%MOD*p[j]%MOD);
        sum=1LL*sum*n%MOD;
        for(int j=1;j<=min(k,i);j++) dec(sum,1LL*(i-j)*q[i-j]%MOD*p[j]%MOD);
        q[i]=1LL*sum*pow_mod(i,MOD-2)%MOD*pow_mod(p[0],MOD-2)%MOD;
        add(ans,1LL*q[i]*i%MOD); add(s,q[i]);
    }
    add(ans,1LL*x*(MOD+1-s)%MOD);
    printf("%d\n",ans);
    return 0;
}