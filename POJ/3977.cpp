#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
const int maxn=1000005;

int n,m,p;
ll a[35];

struct node
{
    ll val;
    int len;
} nod1[maxn],nod[maxn];

//map <ll,int> mq;   //主要控制存在数里面存最小的

int erfen(ll x)
{
    int l=0,r=p-1,mid;
    while(r>=l)
    {
        mid=(l+r)>>1;
        if(nod[mid].val>=x) r=mid-1;
        else l=mid+1;
    }

    return l;
}

int cmp(node p1,node p2)
{
    if(p1.val<p2.val) return 1;
    if(p1.val==p2.val&&p1.len<p2.len) return 1;
    return 0;
}

int main()
{
    int i;

    int x,s,res;
    ll ans;
    while(cin>>n&&n)
    {
        for(i=0; i<n; i++)
            cin>>a[i];

        ans=1e15+5,res=50;
        m=n/2;  //前面用来枚举，后面用来二分.

        //mq.clear();
        s=1<<(n-m);
        for(x=1; x<s; x++) //建立二分数据库
        {
            int tt=x;
            ll tmp=0;

            int cnt=0;
            for(i=m; i<n; i++)
            {
                if(tt&1)
                {
                    tmp+=a[i];
                    cnt++;
                }
                tt>>=1;
            }

            nod1[x].val=tmp;
            nod1[x].len=cnt;
        }

        sort(nod1+1,nod1+s,cmp);

        nod[0].val=0;
        nod[0].len=0;
        nod[1].val=nod1[1].val;
        nod[1].len=nod1[1].len;

        p=2;
        for(i=2;i<s;i++)
        {
            if(nod1[i].val!=nod[p-1].val)
            {
                nod[p].val=nod1[i].val;
                nod[p++].len=nod1[i].len;
            }
        }

        sort(nod,nod+p,cmp);
        //for(i=0;i<p;i++)
            //cout<<nod[i].val<<" "<<nod[i].len<<" eh"<<endl;

        s=1<<m;
        for(x=0; x<s; x++)
        {
            ll tt=x,tmp=0;

            int cnt=0;
            for(i=0; i<m; i++)
            {
                if(tt&1)
                {
                    tmp+=a[i];
                    cnt++;
                }
                tt>>=1;
            }

            int pos=erfen(-tmp);
            int pos1=max(pos-1,0),pos2=min(pos+1,p-1);

            for(i=pos1; i<=pos2; i++)
            {
                ll tmp1=nod[i].val+tmp;
                int tmp2=nod[i].len+cnt;
                if(tmp1==0&&tmp2==0) continue;  //不能什么都不取
                if(tmp1<0) tmp1=-tmp1;
                if(tmp1<ans||(tmp1==ans&&tmp2<res))
                {
                    ans=tmp1;
                    res=tmp2;
                }
            }
        }

        cout<<ans<<" "<<res<<endl;
    }

    return 0;
}