#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN],b[MAXN],vis[MAXN];
vector<int> G[MAXN];
vector<int> dis;
int num,cnt[MAXN],ans[MAXN];
void go(int v)
{
    int t=0;
    int now=v;
    vector<int> vv;
    while(!vis[now])
    {
        vv.push_back(now);
        vis[now]=++t;
        now=b[now];
    }
    int len=t+1-vis[now];
    set<int> good;
    map<int,int> mp; mp.clear();
    for(int i=(int)vv.size()-len;i<(int)vv.size();i++) good.insert(a[vv[i]]); 
    for(auto x:vv) vis[x]=0;
    queue<int> que; mp[a[now]]++; vis[now]=1; que.push(now);
    while(que.size())
    {
        int x=que.front(); que.pop();
        for(auto to:G[x])
        {
            if(!vis[to])
            {
                vis[to]=1;
                mp[a[to]]++;
                que.push(to);
            }
        }
    }
   // puts("good");
   // for(auto x:good) printf("%d ",x);
   // puts("");
    num++;
    for(auto x:good) cnt[x]++,ans[x]+=mp[x];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        num=0;
        for(int i=1;i<=n;i++) G[i].clear();
        dis.clear();
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); dis.push_back(a[i]);}
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        for(int i=1;i<=n;i++) {scanf("%d",&b[i]); G[b[i]].push_back(i);}
        for(int i=1;i<=n;i++) vis[i]=cnt[i]=ans[i]=0;
        for(int i=1;i<=n;i++)
            if(!vis[i]) go(i);
        //printf("num=%d\n",num);
        int res=-1,id=-1;
        for(int i=1;i<=n;i++) if((cnt[a[i]]==num)&&(ans[a[i]]>res)) {res=ans[a[i]]; id=a[i];}
        if(res==-1) puts("-1"); else printf("%d\n",n-res);
    }
    return 0;
}

