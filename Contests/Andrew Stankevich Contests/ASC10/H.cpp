#include<bits/stdc++.h>
#define MAXN 55
#define MAXL 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,m;
string mp[MAXN];
bool vis[MAXN][MAXN];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char d[4]={'R','D','L','U'};
map<char,char> rev;
int w[MAXL][MAXL];
string ans;
//dir:
//0 right
//1 down
//2 left
//3 up
bool checkhole()
{
    assert(mp[0][0]='.');
    memset(vis,false,sizeof(vis));
    queue<P> que;
    que.push(P(0,0)); vis[0][0]=true;
    while(que.size())
    {
        P p=que.front(); que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=p.F+dx[i],ny=p.S+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&mp[nx][ny]=='.'&&mp[nx][ny]=='.'&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                que.push(P(nx,ny));
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='.'&&!vis[i][j]) return true;
    return false;
}
pair<P,int> go(P pos,int dir)
{
    ans+=d[dir];
    if(dir==0)
    {
        if(mp[pos.F][pos.S+1]=='.'&&mp[pos.F+1][pos.S+1]=='*') return make_pair(P(pos.F,pos.S+1),0);
        else if(mp[pos.F][pos.S+1]=='*'&&mp[pos.F+1][pos.S+1]=='*') return make_pair(P(pos.F,pos.S),3);
        else return make_pair(P(pos.F+1,pos.S+1),1);
    }
    else if(dir==1)
    {
        if(mp[pos.F+1][pos.S]=='.'&&mp[pos.F+1][pos.S-1]=='*') return make_pair(P(pos.F+1,pos.S),1);
        else if(mp[pos.F+1][pos.S]=='*'&&mp[pos.F+1][pos.S-1]=='*') return make_pair(P(pos.F,pos.S),0);
        else return make_pair(P(pos.F+1,pos.S-1),2);
    }
    else if(dir==2)
    {
        if(mp[pos.F][pos.S-1]=='.'&&mp[pos.F-1][pos.S-1]=='*') return make_pair(P(pos.F,pos.S-1),2);
        else if(mp[pos.F][pos.S-1]=='*'&&mp[pos.F-1][pos.S-1]=='*') return make_pair(P(pos.F,pos.S),1);
        else return make_pair(P(pos.F-1,pos.S-1),3);
    }
    else 
    {
        if(mp[pos.F-1][pos.S]=='.'&&mp[pos.F-1][pos.S+1]=='*') return make_pair(P(pos.F-1,pos.S),3);
        else if(mp[pos.F-1][pos.S]=='*'&&mp[pos.F-1][pos.S+1]=='*') return make_pair(P(pos.F,pos.S),2);
        else return make_pair(P(pos.F-1,pos.S+1),0);
    }
}
void extract_string()
{   
    P pos=P(-1,-1);
    int dir=-1;
    for(int i=0;i<n;i++)
    {
        if(dir!=-1) break;
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='.'&&mp[i+1][j]=='*')
            {
                pos=P(i,j);
                dir=0; break;
            }
        }
    }
    P tmp=pos; int tdir=dir;
    do
    {
        tie(pos,dir)=go(pos,dir);
        //printf("%d %d %d\n",pos.F,pos.S,dir);
    }while(tmp!=pos||tdir!=dir);
}
string get_substr(int id,int len)
{
    if(id+len<(int)ans.size()) return ans.substr(id,len);
    int x=(int)ans.size()-id;
    return ans.substr(id)+ans.substr(0,len-x);
}
void floyd_warshall(int V)
{
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
          for(int j=0;j<V;j++) 
              w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
}
bool is_congruent(string s,string t)
{
    if(s.size()!=t.size()) return false;
    for(int i=0;i<(int)s.size();i++) if(t[i]!=rev[s[i]]) return false;
    return true;
}
int main()
{
    freopen("tilings.in","r",stdin);
    freopen("tilings.out","w",stdout);
    rev['L']='R'; rev['R']='L'; rev['U']='D'; rev['D']='U';
    while(getline(cin,mp[++tot])) 
    {
        mp[tot]='.'+mp[tot];
        mp[tot]=mp[tot]+'.';
        m=max(m,(int)mp[tot].size());
    }
    tot--;
    mp[0]=mp[tot+1]="";
    for(int i=0;i<m;i++) mp[0]+='.';
    for(int i=0;i<m;i++) mp[tot+1]+='.';
    n=tot+2;
    for(int i=0;i<n;i++) 
        while((int)mp[i].size()<m) 
            mp[i]=mp[i]+'.';
    if(checkhole()) {puts("NO"); return 0;}
    extract_string();
    int sz=(int)ans.size();
    assert(sz%2==0);
    int half=sz/2;
    for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            w[i][j]=(i==j?0:INF);
    for(int i=0;i<sz;i++)
        for(int len=1;len<=half;len++)
        {
            string s=get_substr(i,len);
            string t=get_substr((i+half)%sz,len);
            reverse(t.begin(),t.end());
            if(is_congruent(s,t)) 
            {
                w[i][(i+len)%sz]=w[(i+len)%sz][i]=1;
            }
            else w[i][(i+len)%sz]=w[(i+len)%sz][i]=INF;
        }
    floyd_warshall(sz);
    for(int i=0;i<sz;i++) 
        if(w[i][(i+half)%sz]<=3)
        {
            puts("YES");
            return 0;
        }
    puts("NO");
    return 0;
}
