#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 25
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
int T,n,m;
int rem[7]={3,5,7,11,13,16,17};
int r[MAXN][MAXN],x[MAXN];
int extgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int mod_inverse(int a,int m)
{
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
int solve(vector<P> &v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            r[i][j]=mod_inverse(v[i].S,v[j].S);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        x[i]=v[i].F;
        for(int j=0;j<i;j++)
        {
            x[i]=r[j][i]*(x[i]-x[j]);
            x[i]=x[i]%v[i].S;
            if(x[i]<0) x[i]+=v[i].S;
        }
    }
    int base=1;
    for(int i=0;i<n;i++)
    {
        ans+=base*x[i];
        base*=v[i].S;
    }
    return ans;
}
int ask(int x)
{
    for(int i=0;i<18;i++) printf("%d%c",x,i==17?'\n':' ');
    fflush(stdout);
    int cnt=0;
    for(int i=0;i<18;i++)
    {
        int y; scanf("%d",&y);
        cnt=(cnt+y)%x;
    }
    return cnt;
}
int main()
{
    scanf("%d%d%d",&T,&n,&m);
    for(int t=1;t<=T;t++)
    {
        vector<P> v; v.clear();
        for(int i=0;i<7;i++) v.push_back(P(ask(rem[i]),rem[i]));
        printf("%d\n",solve(v)); fflush(stdout);
        int ret; scanf("%d",&ret); assert(ret==1);
    }
    return 0;
}

