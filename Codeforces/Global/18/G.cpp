#include<bits/stdc++.h>
#define MAXN 605
#define MAXM 300005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,x,y,fore,rear,cnt,ans,father[MAXN],f[MAXN],path[MAXN],tra[MAXN],que[MAXN],match[MAXN];
bool a[MAXN][MAXN],check[MAXN],treec[MAXN],pathc[MAXN];
int c[MAXM];
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
    ans=0;
    for(int i=1;i<=n;i++)
        if(match[i]==0)
        {
            if(find(i)) ans++;
            clear();
        }
}
vector<P> v;
int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++) 
    {
        scanf("%d",&c[i]);
        if(c[i]!=0) v.push_back(P(c[i],i));
    }
    if(!v.size())
    {
        for(int i=1;i<=n;i++) printf("%d ",(i+1)/2);
        puts("");
        return 0;
    }
    int cnt=0;
    n=600;
    for(int )
    for(int i=0;i<(int)v.size()-1;i++)
    {
        int len=v[i+1].S-v[i].S-1;
        if(!len) continue;
        if(len&1)
        {

        }
    }
    matching();
    printf("%d\n",ans);
    return 0;
}