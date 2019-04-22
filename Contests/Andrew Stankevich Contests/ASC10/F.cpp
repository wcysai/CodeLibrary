#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<db,int> P;
const db eps=1e-8;
const db PI=acos(-1.0);
bool clockwise=false;
int n,r,h;
vector<P> a,b,c;
void read(vector<P> &a)
{
    for(int i=1;i<=n;i++)
    {
        db x;
        scanf("%lf",&x);
        while(x<-eps) x+=2*PI;
        while(x>2*PI+eps) x-=2*PI;
        a.push_back(P(x,i));
    }
    sort(a.begin(),a.end());
}
db dis(db x,db y)
{
    db rad=abs(x-y);
    while(rad>2*PI+eps) rad-=2*PI;
    while(rad>PI+eps) rad=2*PI-rad;
    db d=rad*r;
    return sqrt((db)d*d+(db)h*h/4);
}
P solve(vector<P> &a,vector<P> &b)
{
    db ans=INF; int id=-1;
    for(int i=0;i<n;i++)
    {
        db res=0;
        for(int j=0;j<n;j++) res+=dis(a[j].F,b[(j+i)%n].F);
        if(res<ans)
        {
            ans=res;
            id=i;
        }
    }
    return P(ans,id);
}
int main()
{
    //freopen("magic.in","r",stdin);
    //freopen("magic.out","w",stdout);
    scanf("%d%d%d",&n,&r,&h);
    read(a); read(b); read(c);
    P p=solve(b,a); P q=solve(b,c);
    printf("%.15f\n",p.F+q.F); 
    for(int i=0;i<n;i++)
    {
        int id1=a[(i+p.S)%n].S;
        int id2=b[i].S;
        int id3=c[(i+q.S)%n].S;
        printf("%d %d %d\n",id1,id2,id3);
    }
    return 0;
}
