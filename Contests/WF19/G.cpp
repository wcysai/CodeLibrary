#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,state[MAXN];
struct GSAM
{
    vector<int> G[2*MAXN];
    int edges[2*MAXN][26];
    vector<int> link;            
    vector<int> length;
    vector<int> sz;
    int last;                    
    void init()
    {
        memset(edges,0,sizeof(edges));
        link.clear(); length.clear(); 
        link.push_back(-1);
        length.push_back(0);
        last=0;
    }
    int add(int p,char ch) 
    {
        if(edges[p][ch-'A'])
        {
            int q=edges[p][ch-'A'];
            if(length[p]+1==length[q]) return q;
            ++last;
            for(int i=0;i<26;i++) edges[last][i]=edges[q][i];
            length.push_back(length[p]+1); 
            int qq=last; 
            while(p>=0&&edges[p][ch-'A']==q)
            {
                edges[p][ch-'A']=qq;
                p=link[p];
            }
            link.push_back(link[q]); link[q]=qq;
            return qq;
        }
        ++last;
        length.push_back(length[p]+1); link.push_back(0);
        int r=last;
        while(p>=0&&!edges[p][ch-'A']) 
        {
            edges[p][ch-'A']=r;
            p=link[p];
        }
        if(p!=-1) 
        {
            int q=edges[p][ch-'A'];
            if(length[p]+1==length[q]) link[r]=q;
            else 
            {
                ++last;
                for(int i=0;i<26;i++) edges[last][i]=edges[q][i];
                length.push_back(length[p]+1);
                link.push_back(link[q]); 
                int qq=last;
                link[q]=qq; link[r]=qq;
                while(p>=0&&edges[p][ch-'A']==q) 
                {
                    edges[p][ch-'A']=qq;
                    p=link[p];
                }
            }
        }
        return r;
    }
    void build(string &s)
    {
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) cur=add(cur,s[i]);
    }
    void dfs(int v)
    {
        for(auto to:G[v]) {dfs(to); sz[v]+=sz[to];}
    }
    void solve()
    {
        for(int i=1;i<=last;i++) G[link[i]].push_back(i);
        sz.resize(last+1);
        for(int i=1;i<=n;i++) sz[state[i]]++;
        dfs(0);
    }
    int query(string &s)
    {
        int now=0;
        for(int i=0;i<(int)s.size();i++)
        {
            if(!edges[now][s[i]-'A']) return 0;
            now=edges[now][s[i]-'A'];
        }
        return sz[now];
    }
}gsam;
int main()
{
    scanf("%d%d",&n,&k);
    gsam.init();
    for(int i=1;i<=n;i++)
    {
       string s;
       int p;
       cin>>s>>p;
       state[i]=gsam.add(state[p],s[0]);
    }
    gsam.solve();
    for(int i=0;i<k;i++)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        printf("%d\n",gsam.query(s));
    }
    return 0;
}

