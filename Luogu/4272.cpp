#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a,b,x[MAXN];
multiset<ll> l,r;
int main()
{
    scanf("%d%d%d%d",&n,&q,&a,&b);
    ll mini=0,lshift=0,rshift=0;
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    l.insert(x[0]); r.insert(x[0]); 
    //always bounded by [1,Q]
    for(int i=1;i<n;i++)
    {
        //lshift right by A rshift right by B
        lshift+=a; rshift+=b;
        //add by current function
        ll lb=*(--l.end())+lshift,rb=*r.begin()+rshift;
        mini+=max(0LL,max(lb-x[i],x[i]-rb));
        if(x[i]<lb)
        {
            l.insert(x[i]+-lshift); l.insert(x[i]-lshift);
            auto it=--l.end(); r.insert(*it+lshift-rshift); l.erase(it);
        }
        else if(x[i]>rb)
        {
            r.insert(x[i]-rshift); r.insert(x[i]-rshift);
            auto it=r.begin(); l.insert(*it+rshift-lshift); r.erase(it);
        }
        else
        {
            l.insert(x[i]-lshift); r.insert(x[i]-rshift);
        }
        while(r.size()&&*(--r.end())+rshift>q-1LL*(n-i-1)*a) 
        {
            r.erase(--r.end());
            if(!r.size()) r.insert(q-1LL*(n-i-1)*a-rshift);
        }
        while(l.size()&&*(--l.end())+lshift>q-1LL*(n-i-1)*a) 
        {
            l.erase(--l.end());
            if(!l.size()) l.insert(q-1LL*(n-i-1)*a-lshift);
        }
        while(l.size()&&*(l.begin())+lshift<1+1LL*i*a) 
        {
            l.erase(l.begin());
            if(!l.size()) l.insert(1+1LL*i*a-lshift);
        }
        while(r.size()&&*(r.begin())+rshift<1+1LL*i*a) 
        {
            r.erase(r.begin());
            if(!r.size()) r.insert(1+1LL*i*a-rshift);
        }
        for(auto x:l) printf("%lld ",x+lshift);
        puts("");
        for(auto x:r) printf("%lld ",x+rshift);
        puts("");
        //s.insert(x[i]+shift); s.insert(x[i]+shift);
        //s.erase(--s.end());
    }
    printf("%lld\n",mini);
    return 0;
}