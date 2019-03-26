#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 305
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
const double PI=acos(-1.0);
const double eps=1e-6;
int n,E;
double x[MAXN],y[MAXN],r[MAXN];
double d[MAXN];
int sgn(double ta,double tb)
{
    if(fabs(ta-tb)<eps) return 0;
    if(ta<tb) return -1;
    return 1;
}
bool intersect(int i,int j)
{
    double dist2=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    double difr=max(r[i],r[j])-min(r[i],r[j]),sumr=r[i]+r[j];
    return sgn(dist2,sumr*sumr)==-1&&sgn(dist2,difr*difr)==1;
}
struct edge{int from,to; double cost;};
edge es[MAXN*MAXN];
void add_edge(int from,int to,double cost)
{
    es[E++]=(edge){from,to,cost};
}
bool negative_loop()
{
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<E;j++)
        {
            edge e=es[j];
            if(sgn(d[e.to],d[e.from]+e.cost)==1)
            {
                d[e.to]=d[e.from]+e.cost;
                if(i==n) return true;
            }
        }
    }
    return false;
}
int main()
{
    freopen("out.in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)
    {
        scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    }
    for(int i=1;i<=n;i++) r[i]+=r[n+1];
    E=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(intersect(i,j))
            {
                double ang1=atan2(y[i]-y[n+1],x[i]-x[n+1]);
                double ang2=atan2(y[j]-y[n+1],x[j]-x[n+1]);
                double d1=ang2-ang1; if(sgn(d1,PI)==1) d1-=2*PI; if(sgn(d1,-PI)==-1) d1+=2*PI;
                double d2=ang1-ang2; if(sgn(d2,PI)==1) d2-=2*PI; if(sgn(d2,-PI)==-1) d2+=2*PI;
                //printf("%d %d %f %f\n",i,j,d1,d2);
                add_edge(i,j,d1); add_edge(j,i,d2);
            }
        }
    }
    if(negative_loop()) puts("NO"); else puts("YES");
    return 0;
}

