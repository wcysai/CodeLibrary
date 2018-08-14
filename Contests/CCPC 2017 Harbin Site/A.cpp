#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
typedef long long ll;
ll bit[MAXN+1],n,a[2*MAXN],t;
char str[MAXN];
struct save
{
    ll num,id;
}h[MAXN];
struct q
{
    ll l,r,k;
}query[MAXN];
bool cmp1(save x,save y)
{
    return x.num<y.num;
}
bool cmp2(q x,q y)
{
    return x.k<y.k;
}
void manacher(char str[],ll len[],ll n)
{
    len[0]=1;
    for(ll i=1,j=0;i<(n<<1)-1;++i)
    {
        ll p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1&&q+len[i]<n&&str[p-len[i]]==str[q+len[i]])
            ++len[i];
        if(q+len[i]-1>r)
            j=i;
    }
}
ll sum(ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(ll i,ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        memset(bit,0,sizeof(bit));
        scanf("%s",str);
        n=strlen(str);
        manacher(str,a,n);
        for(ll i=1;i<=n;i++)
        {
            a[i]=a[2*(i-1)]-1;
            h[i].num=i-a[i];
            h[i].id=i;
            query[i].l=i+1;
            query[i].r=i+a[i];
            query[i].k=i;
        }
        sort(h+1,h+n+1,cmp1);
        sort(query+1,query+n+1,cmp2);
        ll k1=1,k2=1;
        ll ans=0;
        while(k2<=n)
        {
            while(h[k1].num<=query[k2].k&&k1<=n)
            {
                add(h[k1].id,1);
                k1++;
            }
            ans+=sum(query[k2].r)-sum(query[k2].l-1);
            k2++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
