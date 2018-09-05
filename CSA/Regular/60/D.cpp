#include<bits/stdc++.h>
#define MAXN 1050000
#define INF 1000000000
using namespace std;
typedef long long ll;
struct node
{
    ll a,b,c;
    bool operator<(const node y) const
    {
        if(a!=y.a) return a<y.a;
        if(b!=y.b) return b<y.b;
        return c<y.c;
    }
};
ll n,k;
ll a[40],b[40];
vector<node> save1,save2;
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
        scanf("%lld%lld",&a[i],&b[i]);
    ll half=(n+1)/2;
    for(ll i=0;i<1<<half;i++)
    {
        ll num=__builtin_popcount(i);
        ll s=0;
        for(ll j=0;j<half;j++)
            if((i>>j)&1) s+=a[j]; else s-=b[j];
        save1.push_back((node){s,num,i});
    }
    for(ll i=0;i<1<<(n-half);i++)
    {
        ll num=__builtin_popcount(i);
        ll s=0;
        for(ll j=0;j<n-half;j++)
            if((i>>j)&1) s+=a[half+j]; else s-=b[half+j];
        save2.push_back((node){s,num,i});
    }
    sort(save1.begin(),save1.end());
    sort(save2.begin(),save2.end());
    ll pt1=0,pt2=save2.size()-1;
    ll ans=INF,t=0;
    while(pt1<save1.size())
    {
        while(save1[pt1].a+save2[pt2].a>0)
        {
            pt2--;
            if(pt2<0) break;
        }
        if(pt2<0) break;
        if(save1[pt1].a+save2[pt2].a==0)
        {
            ll sum=save1[pt1].b+save2[pt2].b;
            if(abs(sum*2-n)<ans)
            {
                ans=abs(sum*2-n);
                t=(save1[pt1].c<<(n-half))+save2[pt2].c;
            }
            if(sum*2-n<0) pt1++; else pt2--;
        }
        else pt1++;
    }
    if (ans==INF) printf("-1\n");
    else
    {
        for(ll i=0;i<n;i++)
            if((t>>(n-1-i))&1) printf("1"); else printf("0");
    }
    return 0;
}
