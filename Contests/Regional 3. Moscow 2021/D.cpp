#include<bits/stdc++.h>
#define MAXN 500005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,sz[MAXN];
vector<int> dis;
vector<int> num[MAXN];
vector<int> posi[MAXN];
int ans[MAXN];
bool used[MAXN];
bool erased[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int x;
            scanf("%d",&x);
            dis.push_back(x);
            num[i].push_back(x);
        }
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    memset(used,false,sizeof(used));
    queue<int> que;
    for(int i=1;i<=n;i++)
    {
        sz[i]=num[i].size();
        for(int j=0;j<(int)num[i].size();j++)
        {
            num[i][j]=lower_bound(dis.begin(),dis.end(),num[i][j])-dis.begin()+1;
            posi[num[i][j]].push_back(i);
        }
        sort(num[i].begin(),num[i].end());
        if(sz[i]==1) que.push(i);
    }
    int cnt=0,now=0;
    while(cnt<n)
    {
        while(que.size())
        {
            int v=que.front(); que.pop();
            if(used[v]) continue;
            while(num[v].back()<=now) num[v].pop_back();
            int x=num[v].back(),pos=v;
            while(!used[pos])
            {
                if(num[pos].size()&&num[pos].back()>=x&&*lower_bound(num[pos].begin(),num[pos].end(),x)==x)
                {
                    used[pos]=true; ans[pos]=x; cnt++;
                    pos++; if(pos>n) pos=1;
                }
                else break;
            }
        }
        if(cnt==n) break;
        now++;
        for(auto x:posi[now]) 
        {
            if(used[x]) continue;
            sz[x]--;
            if(sz[x]==1) que.push(x);
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",dis[ans[i]-1]);
    return 0;
}