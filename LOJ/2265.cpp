#include<bits/stdc++.h>
#define MAXN 50005
#define MAXM 505
#define MAXQ 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define conj sadkdsao
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
vector<P> query[MAXN];
int ans[MAXQ];
vector<int> young[MAXM];
vector<int> conj[MAXM];
int bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void ins(int v)
{
    bool added=false;
    int tmp=v;
    for(int i=1;i<=405;i++)
    {
        if(!young[i].size()||v<=young[i].back())
        {
            young[i].push_back(v);
            added=true;
            add(i,1);
            break;
        }
        int pos=upper_bound(young[i].begin(),young[i].end(),v,greater<int>())-young[i].begin();
        swap(young[i][pos],v);
    }
    v=tmp;
    for(int i=1;i<=405;i++)
    {
        if(!conj[i].size()||v>conj[i].back())
        {
            conj[i].push_back(v);
            if(!added) add((int)conj[i].size(),1);
            break;
        }
        int pos=lower_bound(conj[i].begin(),conj[i].end(),v)-conj[i].begin();
        swap(conj[i][pos],v);
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        query[x].push_back(P(y,i));
    }
    for(int i=1;i<=n;i++)
    {
        ins(a[i]);
        for(auto p:query[i]) ans[p.S]=sum(p.F);
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
