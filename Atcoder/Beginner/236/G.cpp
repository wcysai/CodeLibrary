#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<100> bs;
typedef vector<bs> mat;
mat id,G;
int n,t,L;
int u[MAXN*MAXN],v[MAXN*MAXN];
int ans[MAXN];
mat mul(mat A,mat B)
{
    mat C(n);
    for(int i=0;i<n;i++)
    {
        C[i].reset();
        for(int j=0;j<n;j++) if(A[i][j]) C[i]|=B[j];
    }
    return C;
}
mat pow_(mat A,ll n)
{
    mat B=id;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
mat construct(int T)
{
    mat tmp(n);
    for(int i=0;i<n;i++) tmp[i].reset();
    for(int i=1;i<=T;i++)
    {
        tmp[u[i]].set(v[i]);
    }
    return tmp;
}
void solve(int l,int r,vector<int> &id)
{
    if(!id.size()) return;
    if(l>r) return;
    if(l==r)
    {
        for(auto x:id) ans[x]=(l==t+1?-1:l);
        return;
    }
    int mid=(l+r)/2;
    mat tmp=construct(mid);
    tmp=pow_(tmp,L);
    vector<int> lhs,rhs;
    for(auto x:id) if(tmp[0].test(x)) lhs.push_back(x); else rhs.push_back(x);
    solve(l,mid,lhs); solve(mid+1,r,rhs);
}
int main()
{
    scanf("%d%d%d",&n,&t,&L);
    id.resize(n); G.resize(n);
    for(int i=0;i<n;i++)
    {
        id[i].reset();
        id[i].set(i);
    }
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        u[i]--; v[i]--;
    }
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(i);
    }
    solve(1,t+1,v);
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    return 0;
}