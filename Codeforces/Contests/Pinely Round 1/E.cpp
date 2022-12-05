#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool b[MAXN][MAXN];
vector<int> tmp;
vector<int> save;
vector<int> saveall;
int ans;
char str[MAXN];
bool vis[MAXN];
int leaf;
void dfs(int v)
{
    if(vis[v]) return;
    vis[v]=true;
    save.push_back(v);
    bool l=true;
    for(int i=0;i<n;i++)
        if(!vis[i+1]&&b[v-1][i]) {l=false; dfs(i+1); }
    if(l) leaf=v;
}
bool check(int x)
{
    for(auto y:save) if(x!=y&&(!b[x-1][y-1])) return true;
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        tmp.clear(); save.clear(); saveall.clear();
        scanf("%d",&n);
        ans=INF;
        for(int i=0;i<n;i++) 
        {
            scanf("%s",str);
            for(int j=0;j<n;j++) b[i][j]=(str[j]=='1');
        }
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                save.clear(); 
                dfs(i); saveall.push_back(save[0]);
                if(save.size()==n)
                {
                    ans=0; tmp.clear();
                    break;
                }
                else 
                {
                    int id=-1;
                    if(check(leaf)) id=leaf;
                    else 
                    {
                        for(auto x:save) if(check(x)) {id=x; break;}
                    }
                    if(id!=-1) {ans=1; tmp.clear(); tmp.push_back(id); break;}
                    if(save.size()<ans)
                    {
                        ans=(int)save.size();
                        tmp.swap(save);
                    }
                }
            }
        }
        if(ans>2&&saveall.size()>=3) 
        {
            ans=2;
            tmp.clear();
            tmp.push_back(saveall[0]);
            tmp.push_back(saveall[1]);
        }
        printf("%d\n",ans);
        for(auto x:tmp) printf("%d ",x);
        puts("");
    }
    return 0;
}

