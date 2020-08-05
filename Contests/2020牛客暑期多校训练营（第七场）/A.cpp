#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const double PI=acos(-1.0);
int T,n,r;
double ang;
vector<P> v;
vector<int> cur;
int nxt[MAXN],ans,st;
double ag[MAXN];
int table[8][30]=
{
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
4,16,36,64,100,144,196,256,324,400,484,576,676,784,900,1024,1156,1296,1444,1600,1764,1936,2116,2304,2500,2704,2916,3136,3364,3600,
8,32,76,130,224,312,416,554,722,896,1064,1248,1512,1746,2016,2264,2600,2888,3218,3584,3912,4344,4712,5138,5612,6062,6536,6984,7520,8084,
16,64,144,256,400,576,784,1024,1296,1600,1936,2304,2704,3136,3600,4096,4624,5184,5776,6400,7056,7744,8464,9216,10000,10816,11664,12544,13456,14400,
0,88,214,372,624,872,1172,1566,2004,2496,2960,3476,4196,4850,5600,6284,7212,8008,8964,9970,10894,12060,13080,14222,15624,16850,18140,19426,20908,22432,
0,120,312,540,900,1272,1690,2268,2892,3600,4264,5044,6084,7008,8100,9082,10404,11568,12924,14400,15720,17376,18865,20568,22500,24277,26148,27984,30092,32376,
0,152,412,716,1224,1712,2308,3048,3940,4896,5812,6836,8238,9524,10980,12324,14152,15690,17564,19542,21342,23630,25644,27946,30576,32976,35564,38068,40952,43976,
0,192,544,928,1600,2240,3008,4000,5136,6400,7616,8910,10816,12435,14400,16142,18464,20523,23040,25550,27855,30880,33518,36339,39902,43264,46496,49708,53824,57286,
};
int get_dist2(P x,P y)
{
    return (x.F-y.F)*(x.F-y.F)+(x.S-y.S)*(x.S-y.S);
}
double get_ang(P p)
{
    return atan2(p.S,p.F);
}
double get_delta(int i,int j)
{
    double delta=ag[j]-ag[i];
    while(delta<0) delta+=2*PI;
    return delta;
}
void preprocess()
{
    for(int i=0;i<(int)v.size();i++) ag[i]=get_ang(v[i]);
    for(int i=0;i<(int)v.size();i++)
    {
        nxt[i]=-1;
        for(int j=0;j<(int)v.size();j++)
        {
            if(i==j) continue;
            if(nxt[i]==-1||abs(ang-(get_delta(j,i)))<abs(ang-(get_delta(nxt[i],i)))) nxt[i]=j;
        }
    }
}
void dfs(int now,int cnt,int res)
{
    cnt++;
    for(auto x:cur) res+=get_dist2(v[now],v[x]);
    cur.push_back(now);
    if(cnt==n)
    {
        if(res==8084)
        {
            puts("here");
            for(auto x:cur) printf("%d %d\n",v[x].F,v[x].S);
            puts("");
        }
        if(res>ans) ans=res;
        return;
    }
    for(int i=nxt[now]-3;i<=nxt[now]+3;i++)
    {
        int to=(i%(int)v.size()+(int)v.size())%(int)v.size();
        int d1=(now-st+(int)v.size())%(int)v.size();
        int d2=(to-st+(int)v.size())%(int)v.size();
        if(d2<d1) continue;
        dfs(to,cnt,res);
        cur.pop_back();
    }
}
bool cmp(P x,P y)
{
    return atan2(x.S,x.F)>atan2(y.S,y.F);
}
int solve(int n,int r)
{
    ans=0;
    if(n==1) return 0;
    v.clear();
    ang=2*PI/(double)n;
    for(int i=1;i<=r-1;i++)
    {
        int h=(int)sqrt(r*r-i*i);
        while(h*h+i*i>r*r) h--;
        while((h+1)*(h+1)+i*i<=r*r) h++;
        if(h*h+(i+1)*(i+1)<=r*r) continue;
        v.push_back(P(i,h)); v.push_back(P(i,-h));
        v.push_back(P(-i,h)); v.push_back(P(-i,-h));
    }
    v.push_back(P(0,r)); v.push_back(P(0,-r));
    v.push_back(P(r,0)); v.push_back(P(-r,0));
    printf("size=%d\n",(int)v.size());
    preprocess();
    int cnt=(int)v.size();
    for(int i=0;i<cnt;i++)
    {
        st=i;
        cur.clear();
        dfs(i,0,0);
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&r);
        printf("%d,",solve(n,r));
        if(r==30) printf("\n");
    }
}