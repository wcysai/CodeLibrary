/*************************************************************************
    > File Name: 1242.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-31 15:57:13
 ************************************************************************/

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
int n,m;
set<int> G[MAXN];
int h[MAXN],label[MAXN];
vector<int> st[MAXN];
bool vis[MAXN];
vector<int> peo;
void MCS()
{
    memset(vis,false,sizeof(vis));
    memset(h,0,sizeof(h));
    int cur=0;
    for(int i=0;i<=n-1;i++) st[i].clear();
    for(int i=1;i<=n;i++) st[0].push_back(i);
    for(int i=n;i>=1;i--)
    {
        while(1)
        {
            while(st[cur].size()==0) cur--;
            int now=st[cur].back();
            st[cur].pop_back();if(vis[now]) continue;
            vis[now]=true;label[now]=i;peo.push_back(i);
            set<int>::iterator it;
            for(it=G[now].begin();it!=G[now].end();it++)
            {
                int to=*it;
                if(vis[to]) continue;
                h[to]++; st[h[to]].push_back(to); cur=max(cur,h[to]);
            }
            break;
        }
    }
    reverse(peo.begin(),peo.end());
}
void check()
{
    bool f=true;
    for(int i=0;i<n-1;i++)
    {
        int v=peo[i];
        int last=-1,cur=-INF;
        set<int>::iterator it;
        vector<int> tmp;tmp.clear();
        for(it=G[v].begin();it!=G[v].end();it++)
        {
            int to=*it;
            if(label[to]<label[v]) continue;
            tmp.push_back(to);
            if(label[to]>cur) {last=to; cur=label[to];}
        }
        for(int j=0;j<(int)tmp.size();j++)
        {
            if(tmp[j]==last) continue;
            if(!G[last].count(tmp[j])) {f=false; break;}
        }
        if(!f) break;
    }
    if(f) puts("Perfect"); else puts("Imperfect");
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) G[i].clear();
    peo.clear();
    for(int i=0;i<m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        if(u==v) continue;
        G[u].insert(v);G[v].insert(u);
    }
    MCS();
    check();
    return 0;
}

