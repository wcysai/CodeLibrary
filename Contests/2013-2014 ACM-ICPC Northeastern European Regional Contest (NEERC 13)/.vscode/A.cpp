#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,w,h,n;
vector<P> v[MAXN];
string str;
char ch[MAXN];
bool used[MAXN];
char mp[MAXN][MAXN];
void dfs(int now)
{
    if(now==k)
    {
        printf("%d %d\n",w*n,h*n);
        for(int i=0;i<n*h;i++) printf("%s\n",mp[i]);
        exit(0);
    }
    int xx=-1,yy=-1;
    for(int i=0;i<n*h;i++)
    {
        if(xx!=-1) break;
        for(int j=0;j<n*w;j++)
            if(!mp[i][j])
            {
                xx=i;
                yy=j;
                break;
            }
    }
    for(int i=0;i<k;i++)
    {
        if(used[i]) continue;
        bool f=true;
        for(auto p:v[i])
        {
            if(xx+p.F>=0&&xx+p.F<n*h&&yy+p.S>=0&&yy+p.S<n*w&&!mp[xx+p.F][yy+p.S]);
            else {f=false; break;}
        }
        if(f)
        {
            for(auto p:v[i]) mp[xx+p.F][yy+p.S]=ch[i];
            used[i]=true;
            dfs(now+1);
            used[i]=false;
            for(auto p:v[i]) mp[xx+p.F][yy+p.S]=0;
        }
    }
}
int main()
{
    freopen("ascii.in","r",stdin);
    freopen("ascii.out","w",stdout);
    scanf("%d%d%d",&k,&w,&h);
    for(n=1;;n++) if(n*n==k) break;
    for(int t=0;t<k;t++)
    {
        int xx=-1,yy=-1;
        for(int i=0;i<3*h-2;i++)
        {
            cin>>str;
            for(int j=0;j<3*w-2;j++)
            {
                if(str[j]!='.')
                {
                    ch[t]=str[j];
                    if(xx==-1)
                    {
                        xx=i;
                        yy=j;
                    }
                    v[t].push_back(P(i-xx,j-yy));
                }
            }
        }
    }
    dfs(0);
    return 0;
}