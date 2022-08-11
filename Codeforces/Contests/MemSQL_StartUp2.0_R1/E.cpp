#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
string s[3];
int n[3];
void madd(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void mdec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int ans[MAXN];
struct SAM{
    vector<map<char,int>> edges; 
    vector<int> link;            
    vector<int> length;
    vector<int> dp[3];
    vector<bool> used;
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
    void dfs(int v)
    {
        used[v]=true;
        for(auto p:edges[v])
        {
            if(!used[p.S]) dfs(p.S);
            if(p.F=='!') dp[0][v]++;
            else if(p.F=='@') dp[1][v]++;
            else if(p.F=='#') dp[2][v]++;
            else
            {
                for(int i=0;i<3;i++) dp[i][v]+=dp[i][p.S];
            }
        }
        if(v)
        {
            int l=length[link[v]]+1,r=length[v];
            //printf("v=%d p=%d dp0=%d dp1=%d dp2=%d\n",v,link[v],dp[0][v],dp[1][v],dp[2][v]);
            madd(ans[l],1LL*dp[0][v]*dp[1][v]*dp[2][v]%MOD);
            mdec(ans[r+1],1LL*dp[0][v]*dp[1][v]*dp[2][v]%MOD);
        }
    }
    void solve()
    {
        for(int i=0;i<3;i++) dp[i].resize((int)edges.size());
        used.resize((int)edges.size());
        dfs(0);
    }
}sam;
int main()
{
    cin>>s[0]>>s[1]>>s[2];
    for(int i=0;i<3;i++) n[i]=(int)s[i].size();
    int sz=min(n[0],min(n[1],n[2]));
    string str=s[0]+'!'+s[1]+'@'+s[2]+'#';
    sam.init();
    int cur=0;
    for(int i=0;i<(int)str.size();i++) cur=sam.add(cur,str[i]);
    sam.solve();
    for(int i=1;i<=sz;i++) madd(ans[i],ans[i-1]);
    for(int i=1;i<=sz;i++) printf("%d%c",ans[i],i==sz?'\n':' ');
    return 0;
}

