#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w,comb[MAXN][MAXN];
int ins[MAXN][MAXN],way[MAXN][MAXN];
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

int main()
{
    comb[0][0]=1;
    for(int i=1;i<=400;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++) {comb[i][j]=comb[i-1][j-1]; add(comb[i][j],comb[i-1][j]);}
    }
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            for(int k=0;2*k<=min(i-1,j-1);k++)
                add(ins[i][j],1LL*comb[i-1][2*k]*comb[j-1][2*k]%MOD);
    for(int i=1;i<=400;i++)
        for(int j=1;i+j<=400;j++)
            for(int k=0;k<=min(i-1,j-1);k++)
                add(way[i+j][k],1LL*comb[i-1][k]*comb[j-1][k]%MOD);
    int ans=0;
    for(int i=1;i<=h-2;i++)
        for(int j=1;j<=w-2;j++)
            for(int k=0;k<=200;k++)
                add(ans,1LL*ins[i][j]*way[h-i][k]%MOD*way[w-j][k]%MOD*i%MOD*j%MOD);
    add(ans,1LL*h*w*ins[h][w]%MOD);
    printf("%d\n",ans);
    return 0;
}

