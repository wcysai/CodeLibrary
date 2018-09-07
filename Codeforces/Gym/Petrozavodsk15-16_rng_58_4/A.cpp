/*************************************************************************
    
/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 14:01:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
> File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 14:01:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN];
ll prime[MAXN];
bool is_prime[MAXN];
vector<P> v;
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
    {


                v.push_back(P(res.F*now,res.S*cur));
                cur++;
            }
        }
        sort(v.begin(),v.end());
        ll mx=0,mx2=0;
        for(auto it=v.begin();it!=v.end();it++)
        {
            if(it->S>mx) {mx2=mx; mx=it->S; continue;}
            else if(it->S>mx2) {mx2=it->S; continue;}
            else if(it->S<mx2) {v.erase(it); it--;}
        }
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
> File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 14:01:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100> File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 14:01:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
typedef pair<ll,ll> P;
ll n,k,a[MAXN];
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN];
ll prime[MAXN];
bool is_prime[MAXN];
vector<P> v;
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
    {


                v.push_back(P(res.F*now,res.S*cur));
                cur++;
            }
        }
        sort(v.begin(),v.end());
        ll mx=0,mx2=0;
        for(auto it=v.begin();it!=v.end();it++)
        {
            if(it->S>mx) {mx2=mx; mx=it->S; continue;}
            else if(it->S>mx2) {mx2=it->S; continue;}
            else if(it->S<mx2) {v.erase(it); it--;}
        }
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
            P res=v[j];0000000000000000LL
#define MOD 1000000007
#define F first
#define S second
            cur=2;
            for(ll now=x;res.F<=INF/now;now*=x)
            {#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;

            cur=2;
            for(ll now=x;res.F<=INF/now;now*=x)
            {
ll prime[MAXN];
bool is_prime[MAXN];
vector<P> v;
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
    {
        ll x=prime[i],sz=(int)v.size();
        ll cur=1;
        for(ll j=0;j<sz;j++)
        {
            P res=v[j];
            cur=2;
            for(ll now=x;res.F<=INF/now;now*=x)
            {
                v.push_back(P(res.F*now,res.S*cur));
                cur++;
            }
        }
        sort(v.begin(),v.end());
        ll mx=0,mx2=0;
        for(auto it=v.begin();it!=v.end();it++)
        {
            if(it->S>mx) {mx2=mx; mx=it->S; continue;}
            else if(it->S>mx2) {mx2=it->S; continue;}
            else if(it->S<mx2) {v.erase(it); it--;}
        0000000000000000LL
#define MOD 1000000007
#define F first
#define S second
            cur=2;
            for(ll now=x;res.F<=INF/now;now*=x)
            {#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}

            cur=2;
            for(ll now=x;res.F<=INF/now;now*=x)
            {
ll prime[MAXN];
bool is_prime[MAXN];
vector<P> v;
ll sieve(ll n)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
            else if(it->S>mx2) {mx2=it->S; continue;}
            else if(it->S<mx2) {v.erase(it); it--;}
        }
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
        ll x=prime[i],sz=(int)v.size();
        ll cur=1;
        for(ll j=0;j<sz;j++)
        {
        ll x=prime[i],sz=(int)v.size();
        ll cur=1;
        for(ll j=0;j<sz;j++)
        {}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
    {
        ll x=prime[i],sz=(int)v.size();
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        {
            ur++;
            }
        }
        sort(v.begin(),v.end());
        ll mx=0,mx2=0;
        foif(it->S>mxl j=0;j<sz;j++)
        {
            for(ll now=x;res.F<=INF/now;now*=x)
            {
                v.push_back(P(res.F*now,res.S*cur));
          2=mx; mx=it->; continue;}}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000)}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)typedef long long ll;}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}

            cur=2;
            for(ll now=x;res.F<=INF/now;now*=x)
            {
ll prime[MAXN];
bool is_prime[MAXN];
vector<P> v;
ll sieve(ll n)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
            else if(it->S>mx2) {mx2=it->
    {
        ll x=prime[i],sz=(int)v.size()}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}}
        if((int)v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;0
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++);
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;
            }
        }
        sort(v.begin(),v.end());
        ll mx=0,mx2=0;
        foif(it->S>mxl j=0;j<sz;j++)
        {
            for(ll now=x;res.F<=INF/now;now*=x);
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;
            {
                v.push_back(P(res.F*now,res.S*cur));
          2=mx; mx=it->; continue;}S; continue;}
            else if(it->S<mx2) {v.erase(it); it--;}
        })v.size()==last) break; else last=(int)v.size();
    }
    scanf("%lld",&n);;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++);
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    for(ll i=0;i<p;i++);
        ll cur=1;
        if((int{mr(auto it=v.begin();it!=v.end();it++)
        }
    }
    return p;
}
int main()
{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    for(ll i=0;i<p;i++)
        {{
    ll p=sieve(100000);
    v.pus{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    for(ll i=0;i<p;i++)
        {
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;
            ur++;{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
        {
            ur++;{
    ll p=sieve(100000);
    v.push_back(P(1,1));
    ll last=0;
    for(ll i=0;i<p;i++)
        {
            ur++;;
    if(n>(int)v.size()) puts("-1"); else printf("%lld\n",v[n-1].F);
    return 0;
}
        ll x=prime[i],sz=(int)v.size();
        ll cur=1;
        for(ll j=0;j<sz;j++)
        {
        for(ll j=0;j<sz;j++)
        {
            P res=v[j];
            cur=2;
        ll x=prime[i],sz=(int)v.size();
        ll cur=1;
        for(l      c) xS
