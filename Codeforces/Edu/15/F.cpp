#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 32
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define dec sbcjb
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,k;
P p[MAXN];
set<P> buc[MAXM];
int res[MAXM];
ll dec[MAXM];
int ans[MAXN];
int l[MAXM],r[MAXM];
bool cmp(P p,P q)
{
    if(p.F!=q.F) return p.F>q.F;
    return p.S<q.S;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%lld",&p[i].S,&p[i].F);
    for(int i=1;i<=30;i++)
    {
        l[i]=(1<<(i-1));
        r[i]=(1<<i)-1;
    }
    sort(p,p+n,cmp);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int x; scanf("%d",&x);
        buc[32-__builtin_clz(x)].insert(P(x,i));
    }
    for(int i=0;i<n;i++)
    {
        int pos=32-__builtin_clz(p[i].S);
        //same bucket
        while(buc[pos].size()&&((--buc[pos].end())->F)-dec[pos]>=p[i].S)
        {
            auto it=buc[pos].end(); it--;
            P q=*it; buc[pos].erase(it);
            ll rem=q.F-dec[pos]-p[i].S;
            ans[q.S]+=(res[pos]+1);
            if(rem)
            {
                for(int k=pos-1;k>=1;k--)
                {
                    if(rem>=l[k]&&rem<=r[k])
                    {
                        buc[k].insert(P(rem+dec[k],q.S));
                        ans[q.S]-=res[k];
                        break;
                    }
                }
            }
        }
        for(int j=pos+1;j<=30;j++)//larger bucket
        {
            while(buc[j].size()&&(buc[j].begin()->F)-dec[j]-p[i].S<=r[j-1]) 
            {
                P q=*buc[j].begin(); 
                buc[j].erase(buc[j].begin()); 
                ll rem=q.F-dec[j]-p[i].S;
                ans[q.S]+=(res[j]+1);
                if(rem)
                {
                    for(int k=j-1;k>=1;k--)
                    {
                        if(rem>=l[k]&&rem<=r[k])
                        {
                            buc[k].insert(P(rem+dec[k],q.S));
                            ans[q.S]-=res[k];
                            break;
                        }
                    }
                }
            }
            dec[j]+=p[i].S;
            res[j]++;
        }
    }
    for(int i=1;i<=31;i++)
        for(auto p:buc[i])
            ans[p.S]+=res[i];
    for(int i=1;i<=k;i++) printf("%d%c",ans[i],i==k?'\n':' '); 
    return 0;
}

