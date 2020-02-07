#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,tot;
string str;
map<string,int> mp;
string s[MAXN];
double x[MAXN],y[MAXN];
bool shoot[MAXN];
bool valid[MAXN];
double dis[MAXN][MAXN];
int get_id(string str)
{
    if(mp.find(str)==mp.end()) mp[str]=++tot;
    return mp[str];
}
double get_dist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) 
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
vector<int> v,ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        tot=0; mp.clear();
        scanf("%d%d",&n,&m);
        memset(shoot,false,sizeof(shoot));
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            int id=get_id(s[i]);
            scanf("%Lf%Lf",&x[id],&y[id]);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=(i==j?0:INF);
        for(int i=0;i<m;i++)
        {
            int id1,id2,id3;
            cin>>str; id1=get_id(str);
            cin>>str; cin>>str; id2=get_id(str);
            cin>>str; cin>>str; cin>>str; id3=get_id(str);
            shoot[id2]=shoot[id3]=true;
            double d1=get_dist(id1,id2),d2=get_dist(id1,id3);
            double delta=d2-d1;
            dis[id2][id3]=min(dis[id2][id3],delta);
        }
        floyd_warshall();
        bool f=true;
        for(int i=1;i<=n;i++) 
        {
            if(dis[i][i]<-1e-7)
            {
                f=false;
                break;
            }
        }
        if(!f) {puts("IMPOSSIBLE"); continue;}
        v.clear(); ans.clear();
        for(int i=1;i<=n;i++) if(shoot[i]) v.push_back(i);
        vector<P> ord;
        for(auto i:v)
        {
            int cnt=0;
            for(auto j:v) 
            {
                if(dis[i][j]<-1e-7) cnt++;
            }
            ord.push_back(P(cnt,i));
        }
        sort(ord.begin(),ord.end());
        for(int i=0;i<(int)ord.size();i++) if(ord[i].F!=i) f=false;
        if(!f) {puts("UNKNOWN"); continue;}
        reverse(ord.begin(),ord.end());
        for(auto id:ord) cout<<s[id.S]<<' ';
        cout<<endl;
    }
    return 0;
}