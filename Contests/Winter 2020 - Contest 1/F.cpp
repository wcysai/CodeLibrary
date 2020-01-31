#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,tot;
char ch;   
int cnt[MAXN][26],st[MAXN],ed[MAXN],fa[MAXN];
int s[MAXN];
struct edge
{
    int to;
    char ch;
};
vector<edge> G[MAXN];
void add_edge(int u,int v,char ch)
{
    G[u].push_back((edge){v,ch});
    G[v].push_back((edge){u,ch});
}
void dfs(int v,int p)
{
    st[v]=++tot; fa[v]=p;
    for(auto e:G[v])
    {
        int to=e.to;
        if(to==p) continue;
        dfs(to,v);
    }
    ed[v]=tot;   
}
int main()
{
    
    //freopen("F.in","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
            for(int j=0;j<26;j++)
                cnt[i][j]=0;
        for(int i=1;i<=n;i++) G[i].clear(),s[i]=0;
        for(int i=0;i<n-1;i++)
        {
            int u,v,x; 
            scanf("%d%d %c",&u,&v,&ch);
            add_edge(u,v,ch);            
        }
        dfs(1,0);
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            for(auto e:G[i])
            {
                int to=e.to;
                int x=(int)(e.ch-'a');
                cnt[i][x]++;
            }
            int c=0,id=-1;
            for(int j=0;j<26;j++)
            {
                if(cnt[i][j]>2) f=false;
                if(cnt[i][j]==2) 
                {
                    c++;
                    id=j;
                }
            }
            if(c>1) f=false;
            else if(c==1)
            {     
                s[1]++;
                for(auto e:G[i])
                {
                    int to=e.to;
                    int x=(int)(e.ch-'a');
                    if(x==id)            
                    {
                        if(to==fa[i])
                        {
                            s[1]--;
                            s[st[i]]++; s[ed[i]+1]--;
                        }
                        else
                        {
                            s[st[to]]--; s[ed[to]+1]++;
                        }
                        
                    }
                }
            }
            if(!f) break;
        }
        if(!f) {puts("0"); continue;}
        int ans=0;
        for(int i=1;i<=n;i++) s[i]+=s[i-1];
        for(int i=1;i<=n;i++) if(s[i]==0) ans++; 
        printf("%d\n",ans);
    }
    return 0;
}