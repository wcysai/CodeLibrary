#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,m;
string str[MAXN];
bool valid(string s,string t)
{
    int cnt=0;
    for(int i=0;i<m;i++) if(s[i]==t[i]) cnt++;
    return cnt>=k;
}
int w[MAXN][MAXN];
int cnt,ans;
int rev[MAXN];
bool vis[MAXN];
vector<int> tmp,fans;
bool dfs(int v,int c,bool add=false)
{
    vis[v]=true;
    rev[v]=c;
    cnt+=(c==1);
    tmp.push_back(v);
    if(add&&c) fans.push_back(v);
    for(int i=1;i<=n;i++)
    {
        if(w[v][i])
        {
            int cc=(w[v][i]==1?c^1:c);
            if(vis[i]&&rev[i]!=cc) return false;
            else if(!vis[i]&&!dfs(i,cc,add)) return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        ans=0;
        memset(w,0,sizeof(w));
        for(int i=1;i<=n;i++) cin>>str[i];
        bool f=true;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                w[i][j]=0;
                if(!valid(str[i],str[j])) w[i][j]|=1;
                reverse(str[i].begin(),str[i].end());
                if(!valid(str[i],str[j])) w[i][j]|=2;
                reverse(str[i].begin(),str[i].end());
                if(w[i][j]==3) f=false;
                w[j][i]=w[i][j];
            }
        if(!f) {puts("-1"); continue;}
        tmp.clear(); fans.clear();
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int res=INF,id=-1;
                cnt=0;
                if(dfs(i,0)&&cnt<res)
                {
                    res=cnt;
                    id=0;
                }
                for(auto v:tmp) vis[v]=false;
                tmp.clear();
                cnt=0;
                if(dfs(i,1)&&cnt<res)
                {
                    res=cnt;
                    id=1;
                }
                if(res==INF) {f=false; break;}
                else
                {
                    ans+=res;
                    for(auto v:tmp) vis[v]=false;
                    tmp.clear();
                    dfs(i,id,true);
                    tmp.clear();
                }
            }
        }
        if(!f) puts("-1");
        else
        {
            printf("%d\n",ans);
            for(auto v:fans) printf("%d ",v);
            puts("");
        }
    }
    return 0;
}
