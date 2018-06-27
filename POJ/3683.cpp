#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#define MAXV 3005
#define MAXE 30000
using namespace std;
int V,N;
vector<int> G[MAXE];
vector<int> rG[MAXV];
vector<int> vs;
bool used[MAXV];
int cmp[MAXV];
int S[MAXV],D[MAXV],T[MAXV];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
void solve()
{
    V=N*2;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(min(S[i]+D[i],S[j]+D[j])>max(S[i],S[j]))
            {
                add_edge(i,N+j);
                add_edge(j,N+i);
            }
            if(min(S[i]+D[i],T[j])>max(S[i],T[j]-D[j]))
            {
                add_edge(i,j);
                add_edge(N+j,N+i);
            }
            if(min(T[i],S[j]+D[j])>max(T[i]-D[i],S[j]))
            {
                add_edge(N+i,N+j);
                add_edge(j,i);
            }
            if(min(T[i],T[j])>max(T[i]-D[i],T[j]-D[j]))
            {
                add_edge(N+i,j);
                add_edge(N+j,i);
            }
        }
    }
    scc();
    for(int i=0;i<N;i++)
    {
        if(cmp[i]==cmp[N+i])
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
    for(int i=0;i<N;i++)
    {
        if(cmp[i]>cmp[N+i])
            printf("%02d:%02d %02d:%02d\n",S[i]/60,S[i]%60,(S[i]+D[i])/60,(S[i]+D[i])%60);
        else
            printf("%02d:%02d %02d:%02d\n",(T[i]-D[i])/60,(T[i]-D[i])%60,T[i]/60,T[i]%60);
    }
}
int main()
{
    scanf("%d",&N);
    getchar();
    char str[MAXV];
    for(int i=0;i<N;i++)
    {
        gets(str);
        S[i]=((str[0]-'0')*10+(str[1]-'0'))*60+((str[3]-'0')*10+(str[4]-'0'));
        T[i]=((str[6]-'0')*10+(str[7]-'0'))*60+((str[9]-'0')*10+(str[10]-'0'));
        char* args=&str[12];
        D[i]=atoi(args);
    }
    solve();
    return 0;
}
