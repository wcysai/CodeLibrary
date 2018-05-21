#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <cmath>

using namespace std;
const int maxn=100;
long long lcm,gcd,n;
long long factor[maxn],fac[maxn];
long long Max;
long long aa,bb;
int cnt=0,len=0;
long long multi(long long a,long long b,long long mod){
    long long ret=0;
    while(b){
        if(b&1){
            ret=(ret+a)%mod;
        }
        a=a<<1;
        a=a%mod;
        b=b>>1;
    }
    return ret;
}
long long quickPow(long long a,long long b,long long mod){
    long long ret=1;
    while(b){
        if(b&1)
            ret=multi(ret,a,mod);
        a=multi(a,a,mod);
        b=b>>1;
    }
    return ret;
}
bool witness(long long a,long long n){
    long long m=n-1;
    int j=0;
    while(!(m&1)){
        j++;
        m=m>>1;
    }
    long long x=quickPow(a,m,n);
    if(x==1||x==n-1)
        return false;
    while(j--){
        x=multi(x,x,n);
        if(x==n-1)
            return false;
    }
    return true;
}
bool Miller_Rabin(long long n){
    if(n==2)
        return true;
    if(n<2 || !(n&1))
        return false;
    for(int i=0;i<5;i++){
        long long a=rand()%(n-1)+1;
        if(witness(a,n))
            return false;
    }
    return true;
}
long long Gcd(long long a,long long b){
    return b==0?a:Gcd(b,a%b);
}

long long pollard_rho(long long n,int c){
    long long x,y,d,i=1,k=2;
    x=rand()%(n-1)+1;
    y=x;
    while(1){
        i++;
        x=(multi(x,x,n)+c)%n;
        d=Gcd((y-x+n)%n,n);
        if(1<d && d<n)
            return d;
        if(y==x)
            return n;
        if(i==k){
            y=x;
            k=k<<1;
        }
    }
}
//对n进行质因数分解
void factorFind(long long n,int k){
    if(n==1)
        return;
    if(Miller_Rabin(n)){
        factor[cnt++]=n;
        return;
    }
    long long p=n;
    while(p>=n)
        p=pollard_rho(p,k--);
    factorFind(p,k);
    factorFind(n/p,k);
}
//dfs枚举a和b的值
void dfs(long long a,long long b,int k){
    //如果目前a+b的值已经大于Max了，那么就直接return
    if(a+b>=Max){
        return;
    }
    if(k==len+1){
        if(a+b<Max){
            Max=a+b;
            aa=a;
            bb=b;
        }
        return;
    }
    dfs(a*fac[k],b,k+1);
    dfs(a,b*fac[k],k+1);
}

int main()
{
    long long a,b;
    while(scanf("%I64d%I64d",&gcd,&lcm)!=EOF){
        n=lcm/gcd;
        //若n为素数的话，那aa=1,bb=lcm/gcd。
        if(Miller_Rabin(n)){
            //一开始WA的原因是，当gcd=1的时候，我是输出1,lcm
            //后来才发现，比如1 40，输出5 8
            aa=1;
            bb=n;
            printf("%I64d %I64d\n",aa*gcd,bb*gcd);
        }
        else if(lcm==gcd){
            printf("%I64d %I64d\n",gcd,gcd);
        }
        else{
            cnt=0;
            factorFind(n,120);
            sort(factor,factor+cnt);
            len=0;
            fac[0]=factor[0];
            //这里由于对n分解质因数时，a/gcd 和 b/gcd肯定两两互质，所以先将相同的素因子先乘起来
            //这样后面dfs时aa和bb肯定是两两互质的
            for(int i=1;i<cnt;i++){
                if(factor[i]==factor[i-1]){
                    fac[len]=fac[len]*factor[i];
                }
                else{
                    len++;
                    fac[len]=factor[i];
                }
            }

            //一开始RE，原因如下：
            //当lcm=gcd时，n=lcm/gcd=1，那么a=fac[0]=0，n/a的时候会导致RE。。。
            a=fac[0];
            b=1;
            Max=n/a+a;
            aa=a;
            bb=n/a;
            dfs(a,b,1);
            if(aa>bb){
                long long tmp=aa;
                aa=bb;
                bb=tmp;
            }
            printf("%I64d %I64d\n",aa*gcd,bb*gcd);
        }
    }
    return 0;
}