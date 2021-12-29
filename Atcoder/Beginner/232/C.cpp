#include<bits/stdc++.h>
#define MAXN 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
bool s[MAXN][MAXN];
bool t[MAXN][MAXN];
int p[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    memset(s,false,sizeof(s)); memset(t,false,sizeof(t));
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        s[u][v]=s[v][u]=true;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        t[u][v]=t[v][u]=true;
    }
    for(int i=1;i<=n;i++) p[i]=i;
    bool f=false;
    do
    {
        bool flag=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(s[i][j]!=t[p[i]][p[j]]) flag=false;
        if(flag) f=true;
    } while (next_permutation(p+1,p+n+1));
    if(f) puts("Yes"); else puts("No");
    return 0;
}