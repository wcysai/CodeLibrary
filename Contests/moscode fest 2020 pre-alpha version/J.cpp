#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
int n,c[MAXN];
int ans=1;
bool vis[MAXN];
vector<int> pos[MAXN];
int solve(int l,int r)
{
    int p1=
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++) 
    {
        scanf("%d",&c[i]);
        pos[c[i]].push_back(i);
    }
    memset(vis,false,sizeof(vis));
    int colorcnt=0,cnt=0;
    int last=1;
    for(int i=1;i<=n;i++)
    {
        cnt++;
        if(!vis[c[i]])
        {
            vis[c[i]]=true;
            colorcnt++;
        }
        if(cnt==3*colorcnt) 
        {
            ans=1LL*ans*solve(last,i);
            last=i+1;
        }
     }
}