#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P; 
int n,k;
int x[MAXN],y[MAXN];
int ans[MAXN],need;
int bas[25],rep[25],comb[25];
struct node
{
    int x,y,id;
    int add;
};
vector<node> v;
bool cmp(node p,node q)
{
    if(p.x==q.x) return p.y<q.y;
    return p.x<q.x;
}
int bit[MAXN+1];
int sum(int i)
{
    int s=-1;
    while(i>0)
    {
        s=max(s,bit[i]);
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=MAXN)
    {
        bit[i]=max(bit[i],x);
        i+=i&-i;
    }
}
int use[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        v.push_back((node){x[i],y[i],0});
    }
    for(int i=1;i<=k;i++)
    {
        int j;
        scanf("%d",&j);
        v.push_back((node){x[j],y[j],i});
        v.push_back((node){y[j],x[j],k+i});
    }
    memset(bit,-1,sizeof(bit));
    sort(v.begin(),v.end(),cmp);
    vector<P> tmp;
    for(int i=0;i<(int)v.size();i++)
    {
        if(i==0||v[i].x>v[i-1].x)
        {
            for(auto p:tmp) add(p.F,p.S);
            tmp.clear();
        }
        int val=sum(v[i].y-1)+1;
        if(v[i].id) ans[v[i].id]=val; else tmp.push_back(P(v[i].y,val));
    }
    for(int i=1;i<=k;i++) need^=ans[i];
    for(int i=1;i<=k;i++) ans[i]^=ans[i+k];
    for(int i=1;i<=k;i++)
    {
        int x=ans[i];
        int mask=0;
        for(int j=20;j>=0;j--)
        {
            if(x&(1<<j))
            {
                if(!bas[j])
                {
                    bas[j]=x;
                    rep[j]=i;
                    comb[j]=mask^(1<<j);
                    break;
                }
                x^=bas[j];
                mask^=comb[j];
            }
        }
    }
    int x=need,mask=0;
    for(int j=20;j>=0;j--)
    {
        if(x&(1<<j))
        {
            if(!bas[j]) break;
            x^=bas[j];
            mask^=comb[j];
        }
    }
    if(x) puts("impossible");
    else
    {
        for(int i=20;i>=0;i--) if(mask&(1<<i)) use[rep[i]]=1;
        for(int i=1;i<=k;i++) printf("%d",use[i]);
    }
    return 0;
}