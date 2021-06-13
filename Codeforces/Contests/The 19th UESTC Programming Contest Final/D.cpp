#include<bits/stdc++.h>
#define MAXN 10000005
#define MAXM 4005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int l[MAXM],r[MAXM];
int rev[MAXM];
int perm[MAXM];
vector<pair<P,int> > v,pre,tmp,suf;
int main()
{
    scanf("%d%d",&n,&m);
    v.push_back(make_pair(P(1,n),0));
    for(int i=1;i<=m;i++) 
    {
        scanf("%d%d",&l[i],&r[i]);
        tmp.clear(); pre.clear(); suf.clear();
        int st=1;
        for(auto p:v)
        {
            int len=p.F.S-p.F.F+1;
            int a=p.F.F,b=p.F.S;
            int lb=st,rb=st+len-1;
            if(rb<l[i])
            {
                pre.push_back(p);
            }
            else if(lb>r[i])
            {
                suf.push_back(p);
            }
            else if(lb<=l[i]&&rb>=r[i])//contains reversed interval
            {
                if(p.S==0)//not reversed
                {
                    int x=l[i]-lb,y=r[i]-l[i]+1,z=rb-r[i];
                    if(x) pre.push_back(make_pair(P(a,a+x-1),0));
                    tmp.push_back(make_pair(P(a+x,a+x+y-1),1));
                    if(z) suf.push_back(make_pair(P(a+x+y,a+x+y+z-1),0));
                }
                else
                {
                    int x=l[i]-lb,y=r[i]-l[i]+1,z=rb-r[i];
                    if(x) pre.push_back(make_pair(P(b-x+1,b),1));
                    tmp.push_back(make_pair(P(b-x-y+1,b-x),0));
                    if(z) suf.push_back(make_pair(P(b-x-y-z+1,b-x-y),1));
                }
            }
            else if(lb>=l[i]&&rb<=r[i])//contained in the reversed interval
            {
                auto q=p;
                q.S^=1;
                tmp.push_back(q);
            }
            else if(l[i]>=lb)
            {
                if(p.S==0)//not reversed
                {
                    int x=l[i]-lb,y=rb-l[i]+1;
                    if(x) pre.push_back(make_pair(P(a,a+x-1),0));
                    if(y) tmp.push_back(make_pair(P(a+x,a+x+y-1),1));
                }
                else
                {
                    int x=l[i]-lb,y=rb-l[i]+1;
                    if(x) pre.push_back(make_pair(P(b-x+1,b),1));
                    if(y) tmp.push_back(make_pair(P(b-x-y+1,b-x),0));
                }
            }
            else
            {
                if(p.S==0)//not reversed
                {
                    int x=r[i]-lb+1,y=rb-r[i];
                    if(x) tmp.push_back(make_pair(P(a,a+x-1),1));
                    if(y) suf.push_back(make_pair(P(a+x,a+x+y-1),0));
                }
                else
                {
                    int x=r[i]-lb+1,y=rb-r[i];
                    if(x) tmp.push_back(make_pair(P(b-x+1,b),0));
                    if(y) suf.push_back(make_pair(P(b-x-y+1,b-x),1));
                }
            }
            st+=len;
        }
        reverse(tmp.begin(),tmp.end());
        v.clear();
        for(auto p:pre) v.push_back(p);
        for(auto p:tmp) v.push_back(p);
        for(auto p:suf) v.push_back(p);
    }
    ll ans=0;
    int sz=(int)v.size();
    for(int i=0;i<sz;i++)
        for(int j=i+1;j<sz;j++)
            if(v[i].F.F>v[j].F.F) ans+=1LL*(v[i].F.S-v[i].F.F+1)*(v[j].F.S-v[j].F.F+1);
    for(int i=0;i<sz;i++) if(v[i].S==1) ans+=1LL*(v[i].F.S-v[i].F.F+1)*(v[i].F.S-v[i].F.F)/2;
    printf("%lld\n",ans);
    return 0;
}