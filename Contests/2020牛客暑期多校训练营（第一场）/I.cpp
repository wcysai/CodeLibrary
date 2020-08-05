#include<bits/stdc++.h>
#define MAXN 305
using namespace std;
int n,m,x,y,fore,rear,cnt,ans,father[MAXN],f[MAXN],path[MAXN],tra[MAXN],que[MAXN],match[MAXN];
bool a[MAXN][MAXN],check[MAXN],treec[MAXN],pathc[MAXN];
int u[MAXN],v[MAXN],d[MAXN];
void add_edge(int u,int v)
{
    a[u][v]=a[v][u]=true;
}
inline void push(int x)
{
    que[++rear]=x;
    check[x]=true;
    if(!treec[x])
    {
        tra[++cnt]=x;
        treec[x]=true;
    }
}
int root(int x){return f[x]?f[x]=root(f[x]):x;}

void clear()
{
    for(int i=1,j;i<=cnt;++i)
    {
        j=tra[i];
        check[j]=treec[j]=false;
        father[j]=0,f[j]=0;
    }
}

int lca(int u,int v)
{
    int len=0;
    for(;u;u=father[match[u]])
    {
        u=root(u);
        path[++len]=u;
        pathc[u]=true;
    }
    for(;;v=father[match[v]])
    {
        v=root(v);
        if(pathc[v]) break;
    }
    for(int i=1;i<=len;++i)
    {
        pathc[path[i]]=false;
    }
    return v;
}

void reset(int u,int p)
{
    for(int v;root(u)!=p;)
    {
        if(!check[v=match[u]]) push(v);
        if(f[u]==0) f[u]=p;
        if(f[v]==0) f[v]=p;
        u=father[v];
        if(root(u)!=p) father[u]=v;
    }
}

void flower(int u,int v)
{
    int p=lca(u,v);
    if(root(u)!=p) father[u]=v;
    if(root(v)!=p) father[v]=u;
    reset(u,p),reset(v,p);
}

bool find(int x)
{
    fore=rear=cnt=0,push(x);
    while(fore++<rear)
    {
        int i=que[fore];
        for(int j=1;j<=n;++j)
        {
            if(a[i][j]&&root(i)!=root(j)&&match[j]!=i)
              if(match[j]&&father[match[j]])
                 flower(i,j);
              else if(father[j]==0)
              {
                  father[j]=i;
                  tra[++cnt]=j;
                  treec[j]=true;
                  if(match[j])
                    push(match[j]);
                  else
                  {
                      for(int k=i,l=j,p;k;l=p,k=father[l])
                      {
                          p=match[k];
                          match[k]=l;
                          match[l]=k;
                      }
                      return true;
                  }
              }
        }
    }
    return false;
}

void matching()
{
    for(int i=1;i<=n;i++)
        if(match[i]==0)
        {
            if(find(i)) ans++;
            clear();
        }
}
vector<int> vec[MAXN];
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++) vec[i].clear();
        memset(a,false,sizeof(a));
        memset(father,0,sizeof(father));
        memset(f,0,sizeof(f));
        memset(path,0,sizeof(path));
        memset(tra,0,sizeof(tra));
        memset(que,0,sizeof(que));
        memset(match,0,sizeof(match));
        memset(check,false,sizeof(check));
        memset(treec,false,sizeof(treec));
        memset(pathc,false,sizeof(pathc));
        int s=0,tot=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&d[i]);
            s+=d[i];
            for(int j=0;j<d[i];j++)
            {
                vec[i].push_back(++tot);
            }
        }
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int u=++tot,v=++tot;
            add_edge(u,v);
            for(auto vv:vec[x]) add_edge(vv,u);
            for(auto vv:vec[y]) add_edge(vv,v);
        }
        n=tot;
        ans=0;
        matching();
        if(ans*2==n) puts("Yes"); else puts("No");
    }
    return 0;
}
