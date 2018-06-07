/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-07 09:46:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int _mod(int x,int m)
{
    return x>=m?x-m:x;
}
int mul_mod(int a,int i,int m)
{
    if(i==0) return 0;
    int s=0;
    while(i)
    {
        if(i&1) s=_mod(s+a,m);
        a=_mod(a+a,m);
        i>>=1;
    }
    return s;
}
int pow_mod(int a,int i,int n)
{
    if(i==0) return 1%n;
    int temp=pow_mod(a,i>>1,n);
      temp=mul_mod(temp,temp)%n;
    if(i&1) temp=_mod(temp*a)%n;
    return temp;
}
bool test(int n,int a,int d)
{
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1)) d=d>>1;
    int t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(long long)t*t%n;
        d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}
bool isPrime(int n)
{
    if(n<2) return false;
    int a[]={2,3,5,7,61};
    for(int i=0;i<=4;++i) if(!test(n,a[i],n-1)) return false;
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(isPrime(n)) puts("Yes"); else puts("No");
    }
    return 0;
}


