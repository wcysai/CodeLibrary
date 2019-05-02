#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string trump;
string a[MAXN],b[MAXN];
char rank[9]={'6','7','8','9','T','J','Q','K','A'};
map<char,int> mp;
vector<int> G[MAXN];
vector<string> s,t;
int match[MAXN];
bool used[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||(!used[w]&&dfs(w)))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching(int V)
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=1;v<=V;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v)) res++;
        }
    }
    return res;
}
void init()
{
    mp['6']=0; mp['7']=1; mp['8']=2; mp['9']=3; mp['T']=4;
    mp['J']=5; mp['Q']=6; mp['K']=7; mp['A']=8;
}
bool istrump(string str)
{
    return str[1]==trump[0];
}
bool cover(string s,string t)
{
    if(!istrump(s)&&istrump(t)) return true;
    if(s[1]==t[1]&&mp[s[0]]<mp[t[0]]) return true;
    return false;
}
bool check(int mask)
{
    s.clear(); t.clear();
    for(int i=1;i<=2*n;i++) G[i].clear();
    for(int i=1;i<=n;i++)
    {
        int rk=mp[a[i][0]];
        if(!(mask&(1<<rk))) continue;
        s.push_back(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int rk=mp[b[i][0]];
        if(!(mask&(1<<rk))) continue;
        t.push_back(b[i]);
    } 
    if(s.size()>t.size()) return false;
    for(int i=0;i<(int)s.size();i++)
        for(int j=0;j<(int)t.size();j++)
            if(cover(s[i],t[j])) add_edge(i+1,(int)s.size()+j+1);
    return bipartite_matching((int)s.size()+(int)t.size())==(int)s.size();
}
int main()
{
    freopen("fool.in","r",stdin);
    freopen("fool.out","w",stdout);
    init();
    scanf("%d",&n);
    cin>>trump;
    int rk=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i].size()==3) rk=mp[a[i][0]];
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int mask=0;mask<(1<<9);mask++)
    {
        if(!(mask&(1<<rk))) continue;
        if(check(mask))
        {
            puts("COVER");
            return 0;
        }
    }
    puts("TAKE");
    return 0;
}
