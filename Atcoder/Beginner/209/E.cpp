#include<bits/stdc++.h>
#define MAXN 400005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot;
map<string,int> mp;
vector<int> G[MAXN],rG[MAXN];
int wincnt[MAXN];
int state[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    rG[v].push_back(u);
}
int get_id(string &str)
{
    if(mp.find(str)==mp.end()) mp[str]=++tot;
    return mp[str];
}
string str[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        string pre=str[i].substr(0,3);
        string suf=str[i].substr((int)str[i].size()-3,3);
        add_edge(get_id(pre),get_id(suf));
    }
    queue<P> que;
    memset(state,-1,sizeof(state));
    for(int i=1;i<=tot;i++) if(G[i].size()==0) {state[i]=0; que.push(P(i,0));}
    while(que.size())
    {
        P p=que.front(); que.pop();
        if(p.S==1)
        {
            for(auto to:rG[p.F]) 
            {
                wincnt[to]++;
                if(wincnt[to]==(int)G[to].size()&&state[to]==-1)
                {
                    state[to]=0;
                    que.push(P(to,0));
                }
            }
        }
        else 
        {
            for(auto to:rG[p.F]) 
            {
                if(state[to]==-1)
                {
                    state[to]=1;
                    que.push(P(to,1));
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        string suf=str[i].substr((int)str[i].size()-3,3);
        if(state[get_id(suf)]==0) puts("Takahashi");
        else if(state[get_id(suf)]==1) puts("Aoki");
        else puts("Draw");
    }
    return 0;
}