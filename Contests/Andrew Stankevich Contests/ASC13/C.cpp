#include<bits/stdc++.h>
#define MAXN 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef double db;
typedef vector<db> vec;
typedef vector<vec> mat;
const db eps=1e-10;
bool eq(db a,db b)
{
    return fabs(a-b)<eps;
}
bool ls(db a,db b)
{
    return a<b&&!eq(a,b);
}
pair<bool,vec> simplex(mat a)
{
    int n=(int)a.size()-1;
    int m=(int)a[0].size()-1;
    vec left(n+1),up(m+1);
    iota(up.begin(),up.end(),0);
    iota(left.begin(),left.end(),m);
    auto pivot=[&](int x,int y)
    {
        swap(left[x],up[y]);
        db k=a[x][y];
        a[x][y]=1;
        vector<int> vct;
        for(int j=0;j<=m;j++)
        {
            a[x][j]/=k;
            if(!eq(a[x][j],0)) vct.push_back(j);
        }
        for(int i=0;i<=n;i++)
        {
            if(eq(a[i][y],0)||i==x) continue;
            k=a[i][y];
            a[i][y]=0;
            for(int j:vct) a[i][j]-=k*a[x][j];
        }
    };
    while(1)
    {
        int x=-1;
        for(int i=1;i<=n;i++) if(ls(a[i][0],0)&&(x==-1||a[i][0]<a[x][0])) x=i;
        if(x==-1) break;
        int y=-1;
        for(int j=1;j<=m;j++) if(ls(a[x][j],0)&&(y==-1||a[x][j]<a[x][y])) y=j;
        if(y==-1) return make_pair(false,vec());
        pivot(x,y);
    }
    while(1)
    {
        int y=-1;
        for(int j=1;j<=m;j++) if(ls(0,a[0][j])&&(y==-1||a[0][j]>a[0][y])) y=j;
        if(y==-1) break;
        int x=-1;
        for(int i=1;i<=n;i++) if(ls(0,a[i][y])&&(x==-1||a[i][0]/a[i][y]<a[x][0]/a[x][y])) x=i;
        if(x==-1) return make_pair(false,vec());
        pivot(x,y);
    }
    vector<db> ans(m+1);
    for(int i=1;i<=n;i++) if(left[i]<=m) ans[left[i]]=a[i][0];
    ans[0]=-a[0][0];
    return make_pair(true,ans);
}
int n;
int a[MAXN][MAXN];
bool check(db x,bool print=false)
{
    mat ca;
    for(int j=0;j<n;j++)
    {
        vec cur; cur.clear();
        for(int i=0;i<n;i++) cur.push_back(-a[i][j]);
        cur.insert(cur.begin(),-x);
        ca.push_back(cur); 
    }
    for(int j=0;j<n;j++)
    {
        vec cur; cur.clear();
        for(int i=0;i<n;i++) cur.push_back(1.0);
        cur.insert(cur.begin(),1.0);
        ca.insert(ca.begin(),cur);
        for(db &x:cur) x*=-1.0;
        ca.insert(ca.begin(),cur);
    }
    vec cur; cur.clear();
    for(int j=0;j<n+1;j++) cur.push_back(0);
    ca.insert(ca.begin(),cur);
    auto res=simplex(ca);
    if(print)
    {
        for(int i=1;i<(int)res.S.size();i++) printf("%.15f ",res.S[i]);
    }
    return res.F;
}
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    db l=-10000,r=10000;
    for(int it=0;it<300;it++)
    {
        db mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%.8f\n",l);
    check(l,true);
    return 0;
}
