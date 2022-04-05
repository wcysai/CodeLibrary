#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1000005
using namespace std;
struct query
{
    int l,r,id;
}save[MAXM];
int cnt[MAXN],a[MAXN],out[MAXM];
int n,m,ans,block;
bool cmp(query x,query y)
{
    if(x.l/block!=y.l/block) return x.l/block<y.l/block;
    if(x.l/block&1) return x.r>y.r; else return x.r<y.r;
}
void add(int pos)
{
    if(cnt[a[pos]]&1) ans++;
    cnt[a[pos]]++;
}
void del(int pos)
{
    if(cnt[a[pos]]%2==0) ans--;
    cnt[a[pos]]--;
}
void update(int cl,int cr,int l,int r)
{
    while(cr<r) add(++cr);
    while(cl>l) add(--cl);
    while(cl<l) del(cl++);
    while(cr>r) del(cr--);
}
int main()
{
    scanf("%d",&n);
    block=(int)sqrt(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        save[i].id=i;
        scanf("%d %d",&save[i].l,&save[i].r);
    }
    sort(save,save+m,cmp);
    memset(cnt,0,sizeof(cnt));
    ans=0;
    for(int i=save[0].l;i<=save[0].r;i++)
    {
        if(cnt[a[i]]&1) ans++;
        cnt[a[i]]++;
    }
    out[save[0].id]=ans;
    int cl=save[0].l,cr=save[0].r;
    for(int i=1;i<m;i++)
    {
        update(cl,cr,save[i].l,save[i].r);
        out[save[i].id]=ans;
        cl=save[i].l;
        cr=save[i].r;
    }
    for(int i=0;i<m;i++)
        printf("%d\n",out[i]);
    return 0;
}

