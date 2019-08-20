#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,rem,tot;
int cnt[26],st[26];
vector<int> G[MAXN];
char cc[MAXN];
deque<int> order;
int color[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
}
void dfs_visit(int v)
{
    color[v]=1;
    for(auto to:G[v])
        if(color[to]==0)
            dfs_visit(to);
    color[v]=2;
    order.push_front(v);
}
void toposort()
{
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++)
        if(!color[i]) dfs_visit(i);
}
bool ask(string str)
{
    cout<<"? "<<str<<endl;
    string s;
    cin>>s;
    if(s=="YES") return true; else return false;
}
void go(string str)
{
    cout<<"! "<<str<<endl;
    exit(0);
}
int find_occurences(int x)
{
    string str;
    int l=0,r=rem+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        str="";
        for(int j=0;j<mid;j++) str+=(char)('a'+x);
        if(ask(str)) l=mid; else r=mid;
    }
    return l;
}
void find_relationship(int x,int y)
{
    if(cnt[x]>cnt[y]) swap(x,y);
    if(!cnt[x]) return;
    string str="";
    int rem=cnt[y];
    int done=0;
    for(int pos=0;pos<=cnt[x];pos++)
    {
        int l=0,r=rem+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            str="";
            for(int j=0;j<pos;j++) str+=(char)('a'+x);
            for(int j=0;j<mid;j++) str+=(char)('a'+y);
            for(int j=0;j<cnt[x]-pos;j++) str+=(char)('a'+x);
            if(ask(str)) l=mid; else r=mid;
        }
        rem-=l;
        if(l)
        {
            if(pos!=0) add_edge(st[x]+pos-1,st[y]+done);
            if(pos!=cnt[x]) add_edge(st[y]+done+l-1,st[x]+pos);
        }
        done+=l;
    }
}
int main()
{
    rem=500;
    for(int i=0;i<26;i++)
    {
        int x=find_occurences(i);
        cnt[i]=x; n+=x; rem-=x;
    }
    for(int i=0;i<26;i++)
    {
        if(i==0) st[i]=1;
        else st[i]=st[i-1]+cnt[i-1];
        for(int j=st[i];j<=st[i]+cnt[i]-1;j++)
        {
            if(j!=st[i]+cnt[i]-1) add_edge(j,j+1);
            cc[j]=(char)('a'+i);
        }
    }
    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
            find_relationship(i,j);
    toposort();
    string ans="";
    for(auto x:order) ans+=cc[x];
    go(ans);
    return 0;
}
