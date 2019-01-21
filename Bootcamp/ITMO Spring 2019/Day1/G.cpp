#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD1 121
#define MOD2 61
#define MOD3 45161
#define PHI1 110
#define PHI2 60
#define PHI3 45160
#define PR1 48
#define PR2 35
#define PR3 41511
#define INV1 58
#define INV2 7
#define INV3 44431
#define P1 85
#define P2 18
#define P3 20756
#define Q1 37
#define Q2 44
#define Q3 24406
#define F first
#define S second
using namespace std;
typedef long long ll;
int t,n,k,a[MAXN];
int MOD[3]={121,61,45161};
int PHI[3]={110,60,45160};
int PR[3]={48,35,41511};
int INV[3]={58,7,44431};
int P[3]={85,18,20756};
int Q[3]={37,44,24406};
int ans[3][3];
int pow_mod(int a,int i,int m)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    //printf("%d %d %d\n",pow_mod(PR1,109,MOD1),(1LL*(PR1+1)*(MOD1+1)/2)%MOD1,(1LL*(1-PR1+MOD1)*(MOD1+1)/2)%MOD1);
    //printf("%d %d %d\n",pow_mod(PR2,MOD2-2,MOD2),(1LL*(PR2+1)*(MOD2+1)/2)%MOD2,(1LL*(1-PR2+MOD2)*(MOD2+1)/2)%MOD2);
    //printf("%d %d %d\n",pow_mod(PR3,MOD3-2,MOD3),(1LL*(PR3+1)*(MOD3+1)/2)%MOD3,(1LL*(1-PR3+MOD3)*(MOD3+1)/2)%MOD3);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<3;i++)
        {
            int ex=k%PHI[i];
            int p=pow_mod(P[i],ex,MOD[i]);
            printf("p=%d\n",p);
            int denom1=p-1; if(denom1<0) denom1+=MOD[i];
            if(denom1==0) ans[i][0]=1LL*(n%MOD[i])*P[i]%MOD[i];
            else
            {
                denom1=pow_mod(denom1,PHI[i]-1,MOD[i]);
                assert(1LL*denom1*(p-1)%MOD[i]==1);
                ans[i][0]=1LL*(pow_mod(P[i],n%PHI[i],MOD[i])-1)*denom1%MOD[i]*p%MOD[i];
                if(ans[i][0]<0) ans[i][0]+=MOD[i];
            }
            p=pow_mod(Q[i],ex,MOD[i]);
            printf("p=%d\n",p);
            int denom2=p-1; if(denom2<0) denom2+=MOD[i];
            if(denom2==0) ans[i][1]=1LL*(n%MOD[i])*Q[i]%MOD[i];
            else
            {
                denom2=pow_mod(denom2,PHI[i]-1,MOD[i]);
                assert(1LL*denom2*(p-1)%MOD[i]==1);
                ans[i][1]=1LL*(pow_mod(Q[i],n%PHI[i],MOD[i])-1)*denom2%MOD[i]*p%MOD[i];
                if(ans[i][1]<0) ans[i][1]+=MOD[i];
            }
            ans[i][2]=(1LL*(ans[i][0]-ans[i][1]+MOD[i])*INV[i])%MOD[i];
            printf("%d %d %d %d\n",i,ans[i][0],ans[i][1],ans[i][2]);
        }
    }
    return 0;
}

