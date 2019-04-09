#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1e13
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
db a,b,c,d;
db x[6],p[6],q[6],res[6];
int main()
{
    freopen("lab.in","r",stdin);
    freopen("lab.out","w",stdout);
    scanf("%Lf%Lf%Lf%Lf",&a,&b,&c,&d);
    db ans=INF;
    int id=-1;
    x[0]=a; p[0]=b/a; q[0]=max(c/a,d/b); //a,b full
    x[1]=a; q[1]=c/a; p[1]=max(b/a,d/c); //a,c full
    if(b/a*c/a>d/a) x[2]=-1;  //a,d full
    else
    {
        db l=b/a,r=d/c;
        for(int i=0;i<500;i++)
        {
            db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
            if((lb+1)*(d/a/lb+1)<(rb+1)*(d/a/rb+1)) r=rb; else l=lb;
        }
        x[2]=a; p[2]=l; q[2]=(d/a/l);
    }
    swap(a,b); swap(b,d); swap(c,d);
    x[3]=a; p[3]=b/a; q[3]=max(c/a,d/b); //b,d full
    if(b/a*c/a>d/a) x[4]=-1;  //b,c full
    else
    {
        db l=b/a,r=d/c;
        for(int i=0;i<500;i++)
        {
            db lb=l+(r-l)/3.0,rb=l+(r-l)/3.0*2;
            if((lb+1)*(d/a/lb+1)<(rb+1)*(d/a/rb+1)) r=rb; else l=lb;
        }
        x[4]=a; p[4]=l; q[4]=(d/a/l);
    }
    swap(a,b); swap(b,d); swap(c,d);
    x[5]=a; p[5]=b/a; q[5]=max(c/a,d/b); //c,d full
    for(int i=0;i<6;i++) 
    {
        if(x[i]==-1) continue;
        res[i]=(p[i]+1)*(q[i]+1)*x[i];
        if(res[i]<ans)
        {
            ans=res[i];
            id=i;
        }
    }
    printf("%.15Lf\n",ans);
    vector<db> v(4);
    v[0]=(db)1.0,v[1]=v[0]*q[id],v[2]=x[id]/v[0],v[3]=v[2]*p[id];
    if(id<=2) printf("%.15Lf %.15Lf %.15Lf %.15Lf\n",v[0],v[1],v[2],v[3]);
    else if(id<=4) printf("%.15Lf %.15Lf %.15Lf %.15Lf\n",v[2],v[3],v[1],v[0]);
    else printf("%.15Lf %.15Lf %.15Lf %.15Lf\n",v[1],v[0],v[3],v[2]);
    return 0;
}
