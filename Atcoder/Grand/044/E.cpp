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
ll a[MAXN];
int b[MAXN];
double E[MAXN];
ll sumb[MAXN],sumbi[MAXN],sumbi2[MAXN];
ll get_sum(int l,int r)
{
    return sumb[r]-sumb[l-1];
}
ll get_sumb(int l,int r)
{
    return sumbi[r]-sumbi[l-1];
}
ll get_sumb2(int l,int r)
{
    return sumbi2[r]-sumbi2[l-1];
}
ll get_res(int l,int r)
{
    return get_sumb(l,r)-(l-1)*get_sum(l,r);
}
ll calc(int l,int r)
{
    int len=r-l-2;
    return (1LL*r*r-r)*get_sum(l+1,r-1)-(2*r-1)*get_sumb(l+1,r-1)+get_sumb2(l+1,r-1);
}
double get_ans(int l,int r)
{
    ll dif=a[r]-a[l];
    double x=(dif-2*((r-l)*get_sum(l+1,r-1)-get_res(l+1,r-1)))/(double)(r-l);
    return a[l]*(r-l)+x*(r-l-1)*(r-l)/2+calc(l,r);
}
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    int id=-1; ll val=-1;
    for(int i=1;i<=n;i++) if(a[i]>val) {val=a[i]; id=i;}
    rotate(a+1,a+id,a+n+1); rotate(b+1,b+id,b+n+1);
    a[n+1]=a[1]; b[n+1]=b[1];
    for(int i=1;i<=n+1;i++)
    {
        sumb[i]=sumb[i-1]+b[i];
        sumbi[i]=sumbi[i-1]+1LL*i*b[i];
        sumbi2[i]=sumbi2[i-1]+1LL*i*i*b[i];
    }
    v.push_back(1);
    for(int i=2;i<=n+1;i++)
    {
        while(v.size()>=2&&get_ans(v[v.size()-2],v.back())+get_ans(v.back(),i)<get_ans(v[v.size()-2],i)) v.pop_back();
        v.push_back(i);
    }
    double ans=0.0;
    for(int i=1;i<(int)v.size();i++) ans+=get_ans(v[i-1],v[i]);
    E[1]=E[n+1]=a[1];
    printf("%.10f\n",ans/(double)n);
    return 0;
}