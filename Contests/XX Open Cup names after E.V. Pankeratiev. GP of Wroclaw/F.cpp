#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN];
ll cnt[MAXN];
int ans[MAXN];
vector<int> dis;
vector<P> v;
queue<P> que;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        dis.clear(); v.clear();
        for(int i=1;i<=n+1;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            dis.push_back(a[i]);
            v.push_back(P(a[i],i));
        }
        dis.push_back(1);
        sort(v.begin(),v.end());
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n;i++)
        {
            int id=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
            cnt[id]++;
        }
        int sz=(int)dis.size();
        for(int i=sz;i>=2;i--)
        {
            int x=dis[i-1]/dis[i-2];
            cnt[i-1]+=cnt[i]/x;
            cnt[i]%=x;
        }
        bool f=true;
        if(cnt[1]>1) f=false;
        else if(cnt[1]==1)
        {
            for(int i=2;i<=sz;i++) if(cnt[i]) f=false;
        }
        if(!f) puts("NIE");
        else 
        {
            puts("TAK");
            int len=dis.back();
            for(int i=0;i<len;i++) ans[i]=0;
            printf("%d ",len);
            while(que.size()) que.pop();
            que.push(P(1,0));
            for(auto p:v)
            {
                P tmp=que.front(); que.pop();
                assert(p.F%tmp.F==0);
                for(int i=tmp.S;i<len;i+=p.F) ans[i]=p.S;
                for(int i=tmp.S+tmp.F;i<p.F;i+=tmp.F) que.push(P(p.F,i));
            }
            for(int i=0;i<len;i++)  if(ans[i]) printf("%d ",ans[i]); else printf("%d ",1);
            puts("");
        }
    }
    return 0;
}