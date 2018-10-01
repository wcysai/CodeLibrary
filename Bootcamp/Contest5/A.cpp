/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 18:20:12
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

unordered_map<int,int>mp;
int p,q,a,b;
int n,m,ans,t;
int now;
bool flag;

vector<int> aa;
int pow_mod(int a,int i,int p)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%p;
        a=1LL*a*a%p;
        i>>=1;
    }
    return s;
}
bool g_test(int g)
{
    for(int i=0;i<(int)aa.size();i++)
        if(pow_mod(g,(p-1)/aa[i],p)==1)
            return 0;
    return 1;
}
int primitive_root()
{
    int tmp=p-1;
    for(int i=2;i<=tmp/i;i++)
        if(tmp%i==0)
        {
            aa.push_back(i);
            while(tmp%i==0)
                tmp/=i;
        }
    if(tmp!=1)
    {
        aa.push_back(tmp);
    }
    int g=1;
    while(true)
    {
        if(g_test(g)) return g;
        ++g;
    }
}
int extgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int mod_inverse(int a,int m)
{
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
int find_order(int x)
{
    now=x;
    for(int i=0;i<=100;++i)   
    {    
        if(mp.count(now))
        {
            ans = (1LL*i*m+mp[now])%p;
            return ans;
        }
        now=1LL*now*t%p;
    }
    return -1;
}
int main()
{
    scanf("%d%d",&p,&q);
    int g=primitive_root();
    m=1000000;
    int now=1;mp[now]=0,t=pow_mod(g,m,p);t=pow_mod(t,p-2,p);
    for(int i=1;i<=m;i++)
    {
        now=1LL*now*g%p;
        if(!mp.count(now)) mp[now]=i; else break;
    }
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&a,&b);a=a%p;b=b%p;
        if(a==0)
        {
            if(b==1) puts("0");
            else if(b==0) puts("1");
            else puts("-1");
            continue;
        }
        if(b==0) {puts("-1"); continue;}
        int x=find_order(a),y=find_order(b);
        //printf("%d %d\n",x,y);
        if(y==0) {puts("0"); continue;}
        if(x==0) {puts("-1"); continue;}
        int mod=p-1;
        int gg=__gcd(x,mod);if(y%gg) {puts("-1"); continue;}
        x/=gg;y/=gg;mod/=gg;
        printf("%lld\n",1LL*y*mod_inverse(x,mod)%mod);
    }
    return 0;
}
