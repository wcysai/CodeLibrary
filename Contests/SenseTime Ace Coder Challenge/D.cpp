#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define LL long long
#define fi first
#define se second

const LL MAXV=100000+3;
const int MAXE=300000+3;
vector<int> G[MAXV];
int color[MAXV];
int V, E, deg[MAXV], cnt[MAXE];
int head[MAXV];
int save[MAXV], save_id[MAXV];
bool dfs(int v,int c)
{
    color[v]=c;
    for(int i=0;i<G[v].size();i++)
    {
        if(color[G[v][i]]==c) return false;
        if(color[G[v][i]]==0&&!dfs(G[v][i],-c)) return false;
    }
    return true;
}
bool solve()
{
    for(int i=1;i<=V;i++)
        if(color[i]==0)
            if(dfs(i,1)) return false;
    return true;
}
struct HashMap
{
    const static int mod=20011;
    const static int maxn=800003;
    int head[mod];//链表头指针
    int next[maxn];//指向链表下一个节点
    int size;//当前节点数
    int u[maxn], v[maxn] ,val[maxn];//键，值
    void clear()
    {
        size=0;
        memset(head,-1,sizeof head);
    }
    inline void insert(int _u,int _v, int _val)
    {
        if(_u>_v)
            swap(_u, _v);
        int p=(_u*MAXV+_v)%mod;//取模后对应的链
        u[size]=_u;
        v[size]=_v;
        val[size]=_val;
        next[size]=head[p];
        head[p]=size++;
    }
    int find(int _u, int _v)
    {
        if(_u>_v)
            swap(_u, _v);
        int p=(_u*MAXV+_v)%mod;
        for(int i=head[p];~i;i=next[i])//沿着链找到目标值
            if(u[i]==_u && v[i]==_v)
                return val[i];
        return -1;//没找到
    }
}hm;

struct Edge
{
    int from, to, next;
}edge[2*MAXE];


void init()//初始化
{
    hm.clear();
    for(int i=1;i<=V;++i)
    {
        deg[i]=0;
        head[i]=-1;
    }
    for(int i=0;i<E;++i)
        cnt[i]=0;
    save[0]=0;
}

int main()
{
    scanf("%d%d", &V, &E);
    if(E>3*V)
    {
        for(int i=0;i<E;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if(!solve()) puts("0"); else puts("1");
        return 0;
    }
    init();
    for(int i=0;i<E;++i)
    {
        int id=i<<1;
        int u, v;
        scanf("%d%d", &u, &v);
        hm.insert(u, v, i);
        edge[id].from=u;
        edge[id].to=v;
        edge[id].next=head[u];
        head[u]=id;
        id|=1;
        edge[id].from=v;
        edge[id].to=u;
        edge[id].next=head[v];
        head[v]=id;
        ++deg[u];
        ++deg[v];
    }
    bool f=false;
    for(int u=1;u<=V;++u)
    {
        save[0]=0;
        for(int i=head[u];~i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(deg[u]<deg[v] || (deg[u]==deg[v] && u<v))//只从度数小的方向枚举
            {
                save[++save[0]]=v;
                save_id[save[0]]=i;
            }
        }
        for(int i=1;i<=save[0];++i)
        {
            if(f) break;
            for(int j=1;j<i;++j)
            {
                int id=hm.find(save[i], save[j]);
                if(~id)
                {
                    f=true;
                    break;
                }
            }
        }
        if(f) break;
    }
    if(f) puts("1"); else puts("0");
    return 0;
}