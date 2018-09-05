/*************************************************************************
    > File Name: 11F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-08 16:39:39
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 30011
#define REV 15006
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=s*a%MOD;
        a=a*a%MOD;
        i>>=1;
    }
    return s;
}
void FWT(int a[],int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                a[i+j]=(x+y)%MOD,a[i+j+d]=(x-y+MOD)%MOD;     
                //and:a[i+j]=x+y;    
                //or:a[i+j+d]=x+y;    
            }    
}    
    
void UFWT(int a[],int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                int x=a[i+j],y=a[i+j+d];    
                //xor:
                a[i+j]=1LL*(x+y)*REV%MOD,a[i+j+d]=(1LL*(x-y)*REV%MOD+MOD)%MOD;      
                //and:a[i+j]=x-y;    
                //or:a[i+j+d]=y-x;    
            }    
}   
int nbit(int x)
{
    while(x!=(x&-x)) x+=(x&-x);
    return x;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<=k;i++) a[i]=1;
    int len=nbit(k+1);
    FWT(a,len);
    for(int i=0;i<len;i++) a[i]=pow_mod(a[i],n);
    UFWT(a,len);
    int ans=0;
    for(int i=1;i<len;i++) ans=(ans+a[i])%MOD;
    printf("%d\n",ans);
    return 0;
}

