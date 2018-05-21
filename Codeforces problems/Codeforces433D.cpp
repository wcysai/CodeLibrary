#include<bits/stdc++.h>
#define MAXM 100005
#define MAXN 100005
#define MAXK 1000005
#define INF 10000000000000
using namespace std;
typedef long long ll;
ll n,m,k;
ll l[MAXK],r[MAXK];
bool used[MAXN];
ll save[MAXN];
struct fl
{
    ll d,f,t,c;
}a[MAXM];
bool cmp(fl x,fl y)
{
    return x.d<y.d;
}
int main()
{
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    ll maxd=0;
    for(int i=0;i<m;i++)
    {
        scanf("%I64d %I64d %I64d %I64d",&a[i].d,&a[i].f,&a[i].t,&a[i].c);
        maxd=max(maxd,a[i].d);
    }
    sort(a,a+m,cmp);
    fill(l,l+maxd+2,INF);
    fill(r,r+maxd+2,INF);
    memset(used,false,sizeof(used));
    ll cnt=0,ans=0;
    for(int i=0;i<m;i++)
    {
        if(a[i].t==0)
        {
            if(cnt<n)
            {
                if(!used[a[i].f])
                {
                    cnt++;
                    used[a[i].f]=true;
                    save[a[i].f]=a[i].c;
                    ans+=a[i].c;
                    if(cnt==n) l[a[i].d]=ans;
                }
                else
                {
                    ans-=save[a[i].f];
                    save[a[i].f]=min(save[a[i].f],a[i].c);
                    ans+=save[a[i].f];
                }
            }
            else
            {
                ans-=save[a[i].f];
                save[a[i].f]=min(save[a[i].f],a[i].c);
                ans+=save[a[i].f];
                l[a[i].d]=min(ans,l[a[i].d]);
            }
        }
    }
    memset(used,false,sizeof(used));
    ans=0,cnt=0;
    for(int i=m-1;i>=0;i--)
    {
        if(a[i].f==0)
        {
            if(cnt<n)
            {
                if(!used[a[i].t])
                {
                    cnt++;
                    used[a[i].t]=true;
                    save[a[i].t]=a[i].c;
                    ans+=a[i].c;
                    if(cnt==n) r[a[i].d]=ans;
                }
                else
                {
                    ans-=save[a[i].t];
                    save[a[i].f]=min(save[a[i].t],a[i].c);
                    ans+=save[a[i].t];
                }
            }
            else
            {
                ans-=save[a[i].t];
                save[a[i].t]=min(save[a[i].t],a[i].c);
                ans+=save[a[i].t];
                r[a[i].d]=min(r[a[i].d],ans);
            }
        }
    }
    for(int i=1;i<=maxd;i++)
        l[i]=min(l[i-1],l[i]);
    for(int i=maxd;i>=1;i--)
        r[i]=min(r[i],r[i+1]);
    ans=INF;
    for(int i=1;i+k-1<=maxd;i++)
        ans=min(ans,l[i-1]+r[i+k]);
    printf("%I64d\n",ans==INF?-1:ans);
    return 0;
}
