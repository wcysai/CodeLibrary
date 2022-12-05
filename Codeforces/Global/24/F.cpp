#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
ll f[MAXN][MAXN];
bool chosen[MAXN];
int mult[MAXN];
vector<pair<P,ll> > edges;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            scanf("%lld",&f[i][j]);
            f[j][i]=f[i][j];
        }
    memset(chosen,false,sizeof(chosen));
    for(int i=1;i<=n;i++) mult[i]=1;
    for(int i=1;i<=n-1;i++)
    {
        int now=0;
        for(int j=1;j<=n;j++)
            if(!chosen[j]&&(now==0||f[j][j]>=f[now][now])) now=j;
        //now is a leaf
        chosen[now]=true;
        bool fl=false;
        //printf("now=%d\n",now);
        for(int j=1;j<=n;j++)
        {
            if(!chosen[j]&&(1LL*mult[now]*(f[now][now]-f[j][j])==1LL*(n-2*mult[now])*(f[j][j]-f[now][j])))
            {
                fl=true;
                ll dist=f[j][j]-f[now][j];
                assert(dist%mult[now]==0);
                edges.push_back(make_pair(P(now,j),dist/mult[now]));
                mult[j]+=mult[now];
                //printf("j=%d\n",j);
                break;
            }
        }
        //printf("i=%d\n",i);
        assert(fl);
    }
    for(auto p:edges) printf("%d %d %lld\n",p.F.F,p.F.S,p.S);
    return 0;
}

