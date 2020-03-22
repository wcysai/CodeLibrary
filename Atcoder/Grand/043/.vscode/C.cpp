#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 525
#define INF 1000000000000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m[3];
vector<int> G[MAXN];
int sg[3][MAXN];
int weight[3][MAXM];
bool has[MAXM];
int p[3*MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<MOD) a+=MOD;}
int main()
{
    ll x=INF%MOD;
    p[0]=1;
    for(int i=1;i<=300000;i++) p[i]=1LL*p[i-1]*x%MOD;
    scanf("%d",&n);
    for(int i=0;i<3;i++)
    {
        scanf("%d",&m[i]);
        for(int j=1;j<=n;j++) G[j].clear();
        for(int j=0;j<m[i];j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);
            G[x].push_back(y);
        }
        for(int j=n;j>=1;j--)
        {
            memset(has,false,sizeof(has));
            for(auto to:G[j]) has[sg[i][to]]=true;
            int k=0;
            for(;has[k];k++);
            sg[i][j]=k;
            add(weight[i][k],p[j]);
        }
    }
    int ans=0;
    for(int i=0;i<512;i++)
        for(int j=0;j<512;j++)
        {
            int k=i^j;
            add(ans,1LL*weight[0][i]*weight[1][j]%MOD*weight[2][k]%MOD);
        }
    printf("%d\n",ans);
    return 0;
}