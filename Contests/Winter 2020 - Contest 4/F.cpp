#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000001
#define MOD 998244353
#define REV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int g=3; 
int two[31];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int dbit(int x)
{
    while(x!=(x&-x)) x+=(x&-x);
    return x;
}
int pow_mod(int a,int i)
{
    if(i==0) return 1;
    int s=1;
    while(i>0)
     {
         if(i&1) s=(1LL*s*a)%MOD;
         a=(1LL*a*a)%MOD;
         i>>=1;
     }
     return s;
}
int rev(int x,int r)  
{  
    int ans=0;  
    for(int i=0;i<r;i++)  
        if(x&(1<<i)) ans+=1<<(r-i-1);   
    return ans;  
}  
void ntt(int n,int A[],int on)
{
    int r=0,cnt=0,t=n; 
    while(t>1) {cnt++; t/=2;} 
    for(;;r++) if((1<<r)==n)  break;   
    for(int i=0;i<n;i++)  
    {  
        int tmp=rev(i,r);  
        if(i<tmp) swap(A[i],A[tmp]);  
    }  
    for(int s=1;s<=r;s++)  
    {  
        int m=1<<s;  
        int wn=pow_mod(g,(MOD-1)/m);  
        for(int k=0;k<n;k+=m)  
        {  
            int w=1;  
            for(int j=0;j<m/2;j++)  
            {  
                int t,u;  
                t=1LL*w*A[k+j+m/2]%MOD;  
                u=A[k+j];  
                A[k+j]=(u+t);
                if(A[k+j]>=MOD) A[k+j]-=MOD;  
                A[k+j+m/2]=u+MOD-t;
                if(A[k+j+m/2]>=MOD) A[k+j+m/2]-=MOD;
                w=1LL*w*wn%MOD;  
            }  
        }  
    }  
    if(on==-1)  
    {  
        for(int i=1;i<n/2;i++)  
            swap(A[i],A[n-i]);    
        for(int i=0;i<n;i++)  
            A[i]=1LL*A[i]*two[cnt]%MOD;  
    }  
}

int n,a[100005],b[100005],ans[MAXN][MAXN],cnta[MAXN],cntb[MAXN];
void FWT(int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                for(int k=0;k<2048;k++)
                {   
                    int x=ans[i+j][k],y=ans[i+j+d][k];
                    //xor:
                    ans[i+j][k]=(x+y)%MOD,ans[i+j+d][k]=(x-y+MOD)%MOD;     
                    //and:a[i+j]=x+y;    
                    //or:a[i+j+d]=x+y;
                }    
            }    
}    
    
void UFWT(int n)    
{    
    for(int d=1;d<n;d<<=1)    
        for(int m=d<<1,i=0;i<n;i+=m)    
            for(int j=0;j<d;j++)    
            {    
                for(int k=0;k<2048;k++)
                {
                    int x=ans[i+j][k],y=ans[i+j+d][k];
                    //xor:
                    ans[i+j][k]=1LL*(x+y)*REV%MOD,ans[i+j+d][k]=(1LL*(x-y)*REV%MOD+MOD)%MOD;      
                    //and:a[i+j]=x-y;    
                    //or:a[i+j+d]=y-x;
                }    
            }    
}    
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=30;i++)
        two[i]=pow_mod(1<<i,MOD-2); 
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) ans[b[i]][a[i]]++;
    FWT(512);
    for(int i=0;i<512;i++)
    {
        ntt(2048,ans[i],1);
        for(int j=0;j<2048;j++) ans[i][j]=1LL*ans[i][j]*ans[i][j]%MOD*ans[i][j]%MOD*ans[i][j]%MOD;
        ntt(2048,ans[i],-1);
    }
    
    UFWT(512);
    int res=0;
    for(int i=0;i<512;i++)
        for(int j=0;j<2048;j++)
            add(res,1LL*ans[i][j]*pow_mod(j,i)%MOD);
    printf("%d\n",res);
    return 0;
}