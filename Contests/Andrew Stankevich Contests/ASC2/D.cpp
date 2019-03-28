#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
db b1,t1,b2,t2,l,ds,df,g;
db getv(db d1,db d2,db b,db t)
{
    db c=d1*(1-d1/d2);
    b/=c; t/=c;
    if(b>1) return sqrt(g*d2/2*(b+1/b));
    else if(t<1) return sqrt(g*d2/2*(t+1/t));
    else return sqrt(g*d2);
}
db getans(db s)
{
    return max(getv(ds,ds+s,b1,t1),getv(df,df+l-s,b2,t2));
}
int main()
{
    freopen("jumper.in","r",stdin);
    freopen("jumper.out","w",stdout);
    while((scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf",&b1,&t1,&b2,&t2,&l,&ds,&df,&g))!=EOF)
    {
        db lb=0,rb=l;
        for(int i=0;i<100;i++)
        {
            db u=(2*lb+rb)/3,v=(lb+2*rb)/3;
            if(getans(u)<getans(v)) rb=v; else lb=u;
        }
        printf("%.15Lf\n",getans(lb));
    }
    return 0;
}

