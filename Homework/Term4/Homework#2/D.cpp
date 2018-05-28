#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef struct 
{
    int v,pre,len;
}edge;
int t,n,k,x,y;
queue<edge> que;
vector<int> G[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int cnt=0,ans=0;
        scanf("%d%d",&n,&k);
        k*=2;
        for(int i=0;i<n;i++)
            G[i].clear();
        while(que.size()) que.pop();
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&x,&y);
            x--;y--;
            G[x].push_back(y);
            G[y].push_back(x);
            cnt+=2;
            que.push((edge){x,y,1});
            que.push((edge){y,x,1});
        }
        if(k<=cnt) {printf("%d\n",k/2); continue;}
        ans=cnt;
        while(cnt<k)
        {
            edge p=que.front();
            que.pop();
            int v=p.v;
            for(int i=0;i<G[v].size();i++)
            {
                if(G[v][i]==p.pre) continue;
                cnt++;
                ans+=p.len+1;
                if(cnt==k) break;
                que.push((edge){G[v][i],v,p.len+1});
            }
        }
        printf("%d\n",ans/2);
    }
    return 0;
}