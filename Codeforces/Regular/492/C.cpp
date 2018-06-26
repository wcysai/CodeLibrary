/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-25 01:03:54
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,vector<ll> > PP;
ll n,k;
ll ans[MAXN];
set<PP> s1,s2;
ll abx(ll x) {return max(-x,x);}
int  main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        if(x*y>=0)
        {
            pair<P,vector<ll> >p;
            p.x=P(x,y);
            vector<ll> v;
            v.push_back(i);
            p.y=v;
            s1.insert(p);
        }
        else
        {
            pair<P,vector<ll> >p;
            p.x=P(x,y);
            vector<ll> v;
            v.push_back(i);
            p.y=v;
            s2.insert(p);
        }
    }
    while(s1.size()>=2||s2.size()>=2)
    {
        /*for(auto it=s1.begin();it!=s1.end();it++)
        {
            printf("%lld %lld\n",(*it).x.x,(*it).x.y);
            for(ll i=0;i<(ll)(*it).y.size();i++)
                printf("%lld ",(*it).y[i]);
            puts("");
        }*/
        if(s1.size()>=2)
        {
            PP p=*s1.begin();
            s1.erase(s1.begin());
            PP q=*s1.begin();
            s1.erase(s1.begin());
            //printf("%lld %lld %lld %lld",p.x.x,p.x.y,q.x.x,q.x.y);
            if((p.x.x+q.x.x)*(p.x.x+q.x.x)+(p.x.y+q.x.y)*(p.x.y+q.x.y)<=1000000LL*1000000LL)
            {
                if(p.y.size()<q.y.size())
                {
                    q.y.insert(q.y.end(),p.y.begin(),p.y.end());
                    q.x.x+=p.x.x;q.x.y+=p.x.y;
                    if(q.x.x*q.x.y>=0) s1.insert(q); else s2.insert(q);
                }
                else
                {
                    p.y.insert(p.y.end(),q.y.begin(),q.y.end());
                    p.x.x+=q.x.x;p.x.y+=q.x.y;
                    if(p.x.x*p.x.y>=0) s1.insert(p); else s2.insert(p);
                }
            }
            else
            {
                if(p.y.size()<q.y.size())
                {
                    for(ll i=0;i<(ll)p.y.size();i++)
                        p.y[i]*=-1;
                    q.y.insert(q.y.end(),p.y.begin(),p.y.end());
                    q.x.x-=p.x.x;q.x.y-=p.x.y;
                    if(q.x.x*q.x.y>=0) s1.insert(q); else s2.insert(q);
                }
                else
                {
                    for(ll i=0;i<(ll)q.y.size();i++)
                        q.y[i]*=-1;
                    p.y.insert(p.y.end(),q.y.begin(),q.y.end());
                    p.x.x+=q.x.x;p.x.y+=q.x.y;
                    if(p.x.x*p.x.y>=0) s1.insert(p); else s2.insert(p);
                }
            }
        }
        else
        {
            PP p=*s2.begin();
            s2.erase(s2.begin());
            PP q=*s2.begin();
            s2.erase(s2.begin());
            if((p.x.x+q.x.x)*(p.x.x+q.x.x)+(p.x.y+q.x.y)*(p.x.y+q.x.y)<=1000000LL*1000000LL)
            {
                if(p.y.size()<q.y.size())
                {
                    q.y.insert(q.y.end(),p.y.begin(),p.y.end());
                    q.x.x+=p.x.x;q.x.y+=p.x.y;
                    if(q.x.x*q.x.y>=0) s1.insert(q); else s2.insert(q);
                }
                else
                {
                    p.y.insert(p.y.end(),q.y.begin(),q.y.end());
                    p.x.x+=q.x.x;p.x.y+=q.x.y;
                    if(p.x.x*p.x.y>=0) s1.insert(p); else s2.insert(p);
                }
            }
            else
            {
                if(p.y.size()<q.y.size())
                {
                    for(ll i=0;i<(ll)p.y.size();i++)
                        p.y[i]*=-1;
                    q.y.insert(q.y.end(),p.y.begin(),p.y.end());
                    q.x.x-=p.x.x;q.x.y-=p.x.y;
                    if(q.x.x*q.x.y>=0) s1.insert(q); else s2.insert(q);
                }
                else
                {
                    for(ll i=0;i<(ll)q.y.size();i++)
                        q.y[i]*=-1;
                    p.y.insert(p.y.end(),q.y.begin(),q.y.end());
                    p.x.x+=q.x.x;p.x.y+=q.x.y;
                    if(p.x.x*p.x.y>=0) s1.insert(p); else s2.insert(p);
                }
            }
        }
    }
    if(s1.size()==1&&s2.size()==1)
    {
        PP p=*s1.begin();
        PP q=*s2.begin();
        vector<ll> v;
        if((p.x.x+q.x.x)*(p.x.x+q.x.x)+(p.x.y+q.x.y)*(p.x.y+q.x.y)>=1500000LL*1500000LL)
        for(ll i=0;i<(ll)q.y.size();i++)
            q.y[i]*=-1;
        v.insert(v.end(),p.y.begin(),p.y.end());
        v.insert(v.end(),q.y.begin(),q.y.end());
        for(ll i=0;i<(ll)v.size();i++)
            if(v[i]>0) ans[abx(v[i])]=1; else ans[abx(v[i])]=-1;
    }
    else if(s1.size()==1)
    {
        PP p=*s1.begin();
        for(ll i=0;i<(ll)p.y.size();i++)
            if(p.y[i]>0) ans[abx(p.y[i])]=1; else ans[abx(p.y[i])]=-1;
    }
    else
    {
        PP p=*s2.begin();
        for(ll i=0;i<(ll)p.y.size();i++)
            if(p.y[i]>0) ans[abx(p.y[i])]=1; else ans[abx(p.y[i])]=-1;
    }
    for(ll i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    return 0;
}

