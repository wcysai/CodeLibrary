#include<bits/stdc++.h>
#define MAXN 55
#define MAXD 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<P> pos[MAXD];
int p[MAXN];
vector<int> dep[MAXN];
P save[MAXN][MAXN];
vector<P> ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int k;
        int cnt=0;
        while(true)
        {
            scanf("%d",&k);
            if(!k) break;
            cnt++;
            dep[i].push_back(k);
            pos[k].push_back(P(i,cnt));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            save[i][j]=P(-1,-1);
    while(true)
    {
        bool flag=false;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                save[i][j]=P(-1,-1);
        for(int i=1;i<=n;i++) p[i]=i;
        for(int i=1;i<=1000;i++)
        {
            if(flag) break;
            for(auto j:pos[i])
            {
                int x=p[j.F],y=p[j.F+1];
                swap(p[j.F],p[j.F+1]);
                if(x>y) swap(x,y);
                if(save[x][y]==P(-1,-1)) save[x][y]=j; 
                else 
                {
                    int d=dep[save[x][y].F][save[x][y].S-1];
                    for(int k=0;k<(int)pos[d].size();k++) 
                        if(pos[d][k]==save[x][y]) 
                        {
                            pos[d].erase(pos[d].begin()+k);
                            break;
                        }
                    d=i;
                    for(int k=0;k<(int)pos[d].size();k++) 
                        if(pos[d][k]==j) 
                        {
                            pos[d].erase(pos[d].begin()+k);
                            break;
                        }
                    flag=true;
                    break;
                } 
            }
        }
        if(!flag) break;
    }
    for(int i=1;i<=1000;i++)
        for(auto j:pos[i])
            ans.push_back(j);
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}