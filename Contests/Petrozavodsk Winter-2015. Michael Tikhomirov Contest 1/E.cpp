#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m;
vector<int> G[MAXN];
int ans[MAXN];
vector<int> pos;
void gauss_jordan(mat &A,vec &b)
{
    int pt=0;
    for(int i=0;i<n;i++)
    {
        int pivot=-1;
        for(int j=pt;j<n;j++) if(A[j][i]==1) {pivot=j; break;}
        if(pivot==-1) continue;
        swap(A[pt],A[pivot]); swap(b[pt],b[pivot]);
        pos.push_back(i);
        for(int j=pt+1;j<n;j++)
        {
            if(A[j][i]==1)
            {
                for(int k=0;k<n;k++) A[j][k]^=A[pt][k];
                b[j]^=b[pt];
            }
        }
        pt++;
    }
    for(int i=0;i<n;i++)
    {
        bool empty=true;
        for(int j=0;j<n;j++) if(A[i][j]) empty=false;
        if(empty&&b[i])
        {
            puts("IMPOSSIBLE");
            return;
        }
    }
    for(int i=pt-1;i>=0;i--)
    {
        int x=pos[i],v=b[i];
        for(int j=x+1;j<n;j++) if(A[i][j]&&ans[j]) v^=1;
        ans[x]=v;
    }
    for(int i=0;i<n;i++) if(ans[i]) printf("B"); else printf("A");
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    mat A(n,vec(n)); vec b(n);
    for(int i=1;i<=n;i++)
    {
        if(G[i].size()&1)
        {
            A[i-1][i-1]=1;
            for(auto to:G[i]) A[i-1][to-1]=1;
            b[i-1]=1;
        }
        else for(auto to:G[i]) A[i-1][to-1]=1;
    }
    gauss_jordan(A,b);
    return 0;
}
