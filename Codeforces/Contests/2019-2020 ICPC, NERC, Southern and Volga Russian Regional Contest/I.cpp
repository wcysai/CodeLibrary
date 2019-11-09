#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int t,n,m,tot;
P a[MAXN];
ll k;
struct node
{
    ll sum;
    int curpos,nxtpos,rem,id;
    bool operator<(const node &rhs) const
    {
        return sum>rhs.sum;
    }
};
int pre[MAXN],op[MAXN];
int lastid,lastlen;
ll s[MAXN];
vector<P> ans;
vector<int> tmp,opp;
vector<ll> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld%d",&n,&k,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i].F);
            a[i].S=i;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i].F;
        ans.clear();
        for(int i=n;i>=1;i--)
        {
            if(!m) break;
            if(s[i]>k) continue;
            tot=1;
            priority_queue<node> pque;
            pque.push((node){s[i],i,n+1,i-1,1});
            while(pque.size())
            {
                node p=pque.top(); pque.pop();
                lastid=p.id; lastlen=i; ans.push_back(P(i,p.sum));
                m--; if(!m) break;
                if(p.curpos+1!=p.nxtpos&&p.sum+a[p.curpos+1].F-a[p.curpos].F<=k)
                {
                    tot++;
                    pque.push((node){p.sum+a[p.curpos+1].F-a[p.curpos].F,p.curpos+1,p.nxtpos,p.rem,tot});
                    pre[tot]=p.id;
                    op[tot]=1;
                }
                if(p.rem&&p.rem+1!=p.curpos&&p.sum+a[p.rem+1].F-a[p.rem].F<=k)
                {
                    tot++;
                    pque.push((node){p.sum+a[p.rem+1].F-a[p.rem].F,p.rem+1,p.curpos,p.rem-1,tot});
                    pre[tot]=p.id;
                    op[tot]=2;
                }
            }
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%lld %lld\n",p.F,p.S);
        if(ans.size())
        {
            v.clear(); tmp.clear(); opp.clear();
            for(int i=1;i<=lastlen;i++) tmp.push_back(i);
            int cur=lastid;
            while(cur!=1)
            {
                opp.push_back(op[cur]);
                cur=pre[cur];
            }
            reverse(opp.begin(),opp.end());
            for(auto xx:opp)
            {
                int x=tmp.back();
                if(xx==1)
                {
                    tmp.pop_back();
                    tmp.push_back(x+1);
                }
                else
                {
                    tmp.pop_back();
                    v.push_back(a[x].S);
                    int y=tmp.back(); tmp.pop_back(); tmp.push_back(y+1);
                }
            }
            while(tmp.size())
            {
                int x=tmp.back();
                v.push_back(a[x].S);
                tmp.pop_back();
            }
            sort(v.begin(),v.end());
            for(auto x:v) printf("%lld ",x);
            puts("");
        }
    }
    return 0;
}
