#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int t,k;
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;         
    vector<bool> vis;
    vector<int> length;
    vector<ll> cnt,num;
    vector<int> G[MAXN];
    int last;                    
    void init(){
        edges.clear(); link.clear(); length.clear(); 
        edges.push_back(map<char,int>());
        link.push_back(-1);
        length.push_back(0);
        last=0;
    }
    int add(int p,char ch) {
        edges.push_back(map<char,int>());
        length.push_back(length[p]+1); link.push_back(0);
        int r=edges.size()-1;
        while(p>=0&&edges[p].find(ch)==edges[p].end()) {
            edges[p][ch]=r;
            p=link[p];
        }
        if(p!=-1) {
            int q=edges[p][ch];
            if(length[p]+1==length[q]) link[r]=q;
            else {
                edges.push_back(edges[q]); 
                length.push_back(length[p]+1);
                link.push_back(link[q]); 
                int qq=edges.size()-1;
                link[q]=qq; link[r]=qq;
                while(p>=0&&edges[p][ch]==q) {
                    edges[p][ch]=qq;
                    p=link[p];
                }
            }
        }
        return r;
    }
    void dfs_tree(int v)
    {
        for(auto to:G[v])
        {
            dfs_tree(to);
            if(v) cnt[v]+=cnt[to];
        }
    }
    void dfs_num(int v)
    {
        vis[v]=true; num[v]=cnt[v];
        for(auto p:edges[v])
        {
            if(!vis[p.S]) dfs_num(p.S);
            num[v]+=num[p.S];
        }
    }
    void build(string &s,int type){
        init();
        int cur=0;
        for(int i=0;i<(int)s.size();i++) cur=add(cur,s[i]);
        vis.resize(edges.size()); cnt.resize(edges.size()); num.resize(edges.size());  
        if(type==0)
        {
            for(int i=1;i<(int)edges.size();i++) cnt[i]=1;
        }
        else
        {
            for(int i=1;i<(int)edges.size();i++) G[link[i]].push_back(i);
            int cur=0;
            for(int i=0;i<(int)s.size();i++) {cur=edges[cur][s[i]]; cnt[cur]++;}
            dfs_tree(0);
        }
        dfs_num(0);
    }
    string solve(int k)
    {
        if(num[0]<k) return "-1";
        int cur=0;
        string str="";
        while(k>1)
        {
            k-=cnt[cur];
            for(auto p:edges[cur])
            {
                if(num[p.S]>=k)
                {
                    str+=p.F;
                    cur=p.S;
                    break;
                }
                else k-=num[p.S];
            }
        }
        return str;
    }
}sam;

int main()
{
    cin>>str;
    scanf("%d%d",&t,&k);
    sam.build(str,t);
    cout<<sam.solve(k)<<endl;
    return 0;
}

