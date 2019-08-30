#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int T,ans;
bool can[15][15][15];
vector<int> v;
vector<int> a[4];
vector<int> sa[4];
void dfs(int now,int val)
{
    if(now==12)
    {
        if(val>ans)
        {
            ans=val;
            for(int i=0;i<4;i++) sa[i]=a[i];
        }
        return;
    }
    for(int i=0;i<4;i++)
    {
        if((int)a[i].size()<3)
        {
            a[i].push_back(now);
            if((int)a[i].size()==3) dfs(now+1,val+(can[a[i][0]][a[i][1]][a[i][2]]?1:0)); else dfs(now+1,val);
            a[i].pop_back();
            if(!a[i].size()) return;
        }
    }
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        memset(can,false,sizeof(can));
        v.clear();
        for(int i=0;i<4;i++) a[i].clear(),sa[i].clear();
        for(int i=0;i<12;i++)
        {
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        for(int i=0;i<12;i++)
            for(int j=i+1;j<12;j++)
                for(int k=j+1;k<12;k++)
                    if(v[i]+v[j]>v[k]&&v[i]+v[k]>v[j]&&v[j]+v[k]>v[i]) can[i][j][k]=true;
        ans=-1;
        dfs(0,0);
        printf("Case #%d: %d\n",t,ans);
        for(int i=0;i<4;i++) if(can[sa[i][0]][sa[i][1]][sa[i][2]]) printf("%d %d %d\n",v[sa[i][0]],v[sa[i][1]],v[sa[i][2]]);
    }
    return 0;
}

