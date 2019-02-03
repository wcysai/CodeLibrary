#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
struct jewel
{
    ll val,num,color;
};
bool cmp(jewel x,jewel y)
{
    return x.val>y.val;
}
ll n,k,c,val;
multiset<ll> s[MAXN];
vector<jewel> v;
multiset<ll> P,Q,R,S;
multiset<ll> T;
//P: valid additional taken
//Q: valid untaken
//R: valid taken pair
//S: invalid untaken pair
//T: invalid untaken triple
//possible transformations:
//+Q
//-P +S
//-R +T
bool valid[MAXN];
ll save2[MAXN];
ll save3[MAXN];
int main()
{
    memset(save2,0,sizeof(save2));
    memset(save3,0,sizeof(save3));
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&c,&val);
        s[c].insert(val);
    }
    for(ll i=1;i<=k;i++)
    {
        if(!s[i].size()) continue;
        ll res=0;
        auto it=s[i].end(); it--; res+=*it; it--; res+=*it;
        v.push_back((jewel){res,2,i}); S.insert(res); save2[i]=res;
        ll cnt=0;
        while(it!=s[i].begin())
        {
            it--;
            v.push_back((jewel){2*(*it),1,i});
            if(!cnt) {T.insert(res+*it); save3[i]=res+*it;}
            cnt++;
        }
    }
    sort(v.begin(),v.end(),cmp);
    ll now=0;
    ll ans=0;
    memset(valid,false,sizeof(valid));
    for(ll i=1;i<=n;)
    {
        if(v[now].num==1)
        {
            assert(valid[v[now].color]);
            ans+=v[now].val/2;
            P.insert(v[now].val/2);
            assert(Q.count(v[now].val/2));
            Q.erase(Q.find(v[now].val/2));
            now++;i++;
            printf("%lld\n",ans);
        }
        else
        {
            ll choices=-INF;
            if(Q.size())
            {
                auto it=Q.end(); it--;
                choices=max(choices,*it);
            }
            if(P.size()&&S.size())
            {
                auto it=P.begin();
                ll tmp=*it;
                it=S.end(); it--;
                choices=max(choices,*it-tmp);
            }
            if(R.size()&&T.size())
            {
                auto it=R.begin();
                ll tmp=*it;
                it=T.end(); it--;
                choices=max(choices,*it-tmp);
            }
            if(choices==-INF) puts("-1"); else printf("%lld\n",ans+choices);
            ans+=v[now].val;
            ll c=v[now].color;
            assert(!valid[c]);
            valid[c]=true;
            S.erase(S.find(save2[c]));
            if(save3[c]) T.erase(T.find(save3[c]));
            R.insert(save2[c]);
            auto it=s[c].end(); it--; it--; 
            while(it!=s[c].begin())
            {
                it--;
                Q.insert(*it);
            }
            now++;i+=2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

