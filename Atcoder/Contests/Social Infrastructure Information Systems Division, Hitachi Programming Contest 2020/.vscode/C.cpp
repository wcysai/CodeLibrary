#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt0,cnt1,color[MAXN];
vector<int> G[MAXN];
int p[MAXN];
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
bool used[MAXN];
void dfs(int v,int p,int c)
{
    if(c==0) cnt0++; else cnt1++;
    color[v]=c;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,1-c);
    }
}
void fill_rest()
{
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        if(!p[i])
        {
            while(cur<=n&&used[cur]) cur++;
            used[cur]=true;
            p[i]=cur;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0,0);
    if(cnt0<=n/3)
    {
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                tot++;
                if(tot*3>n) break;
                p[i]=tot*3;
                used[tot*3]=true;
            }
        }
        fill_rest();
    }
    else if(cnt1<=n/3)
    {
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==1)
            {
                tot++;
                if(tot*3>n) break;
                p[i]=tot*3;
                used[tot*3]=true;
            }
        }
        fill_rest();
    }
    else
    {
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                tot++;
                if(tot*3-2>n) break;
                p[i]=tot*3-2;
                used[tot*3-2]=true;
            }
        }
        tot=0;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==1)
            {
                tot++;
                if(tot*3-1>n) break;
                p[i]=tot*3-1;
                used[tot*3-1]=true;
            }
        }
        fill_rest();
    }
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
    puts("");
    return 0;
}