#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define MAXN 200005
#define MAXM 850005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr;
int n,x;
ll ans;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//0: bifurcation 
//num: leaf numbered num
inline tr *merge(tr *a,tr *b)
{
    if(a->size()<b->size()) swap(a,b);
    ll res=0;
    tr::iterator it;
    for(it=(*b).begin();it!=(*b).end();it++) res+=a->order_of_key(*it);
    ans+=min(res,1LL*(int)a->size()*(int)b->size()-res);
    for(it=(*b).begin();it!=(*b).end();it++) a->insert(*it);
    delete b;
    return a;
}
tr *solve()
{
    x=read();
    if(x==0)
    {
        return merge(solve(),solve());
    }
    else
    {
        tr *p=new tr;
        p->insert(x);
        return p;
    }
}
int main()
{
    n=read();
    solve();
    printf("%lld\n",ans);
    return 0;
}
