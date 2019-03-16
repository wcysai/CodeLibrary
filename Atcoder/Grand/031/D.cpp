#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k;
vector<int> p,q;
vector<int> id()
{
    vector<int> ret;ret.resize(n);
    for(int i=0;i<n;i++) ret[i]=i;
    return ret;
}
vector<int> getinv(vector<int> &p)
{
    vector<int> ret;ret.resize(n);
    for(int i=0;i<n;i++) ret[p[i]]=i;
    return ret;
}
vector<int> mul(vector<int> p,vector<int> q)
{
    vector<int> ret;ret.resize(n);
    for(int i=0;i<n;i++) ret[i]=p[q[i]];
    return ret;
}
vector<int> pow_(vector<int> &a,int x)
{
    vector<int> ret;ret.resize(n);
    for(int i=0;i<n;i++) ret[i]=i;
    while(x)
    {
        if(x&1) ret=mul(ret,a);
        a=mul(a,a);
        x>>=1;
    }
    return ret;
}
void go()
{
    vector<int> r=getinv(p);
    r=mul(q,r);
    p=q;q=r;
}
//lhs=qp'q'p
//rhs=p'qpq'
int main()
{
    scanf("%d%d",&n,&k);
    p.resize(n);q.resize(n);
    for(int i=0;i<n;i++) {scanf("%d",&p[i]); p[i]--;}
    for(int i=0;i<n;i++) {scanf("%d",&q[i]); q[i]--;}
    if(k==1)
    {
        for(int i=0;i<n;i++) printf("%d ",p[i]+1);
        return 0;
    }
    k-=2;
    while(k%6) {go(); k--;}
    vector<int> lhs=id(),rhs=id();
    lhs=mul(lhs,q);lhs=mul(lhs,getinv(p));lhs=mul(lhs,getinv(q));lhs=mul(lhs,p);
    rhs=mul(rhs,getinv(p));rhs=mul(rhs,q);rhs=mul(rhs,p);rhs=mul(rhs,getinv(q));
    lhs=pow_(lhs,k/6);rhs=pow_(rhs,k/6);
    lhs=mul(lhs,q);lhs=mul(lhs,rhs);
    for(int i=0;i<n;i++) printf("%d ",lhs[i]+1);
    return 0;
}

