#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
int pre[MAXN],suf[MAXN];
vector<int> pos[MAXN];
vector<P> ladd[MAXN];
vector<int> tmp[MAXN];
vector<int> dis;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        dis.clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            dis.push_back(a[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=(int)dis.size();i++) pos[i].clear();
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
            pos[a[i]].push_back(i);
        }
        for(int i=0;i<=n+1;i++) ladd[i].clear();
        for(int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            ladd[l].push_back(P(l,1)); ladd[r+1].push_back(P(l,-1));
        }
        multiset<int> s;
        for(int i=1;i<=n;i++)
        {
            for(auto p:ladd[i])
                if(p.S==1) s.insert(p.F); else s.erase(s.find(p.F));
            pre[i]=(!s.size()?-1:*s.begin());
        }
        int l=n+1,r=0;
        vector<P> v;
        for(int i=1;i<=n;i++)
        {
            int idi=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),i)-pos[a[i]].begin();
            if(pre[i]!=-1)
            {
                int id=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),pre[i])-pos[a[i]].begin();
                if(id!=idi) 
                {
                    if(id+1!=idi)
                    {
                        l=min(l,pos[a[i]][id+1]);
                        r=max(r,pos[a[i]][idi-1]);
                    }
                    v.push_back(P(pos[a[i]][id],i));
                }
            }
        }
        if(!v.size()) puts("0");
        else
        {
            int ans=(l<=r?min(r,n-l+1):INF);
            for(int i=1;i<=n;i++) tmp[i].clear();
            int ub=l;
            int maxi=0,cur=r;
            for(auto p:v) 
            {
                tmp[p.F+1].push_back(p.S);
                ub=min(ub,p.S);
                cur=max(cur,p.F);
            }
            for(int i=1;i<=ub;i++)
            {
                for(auto val:tmp[i]) cur=max(cur,val);
                ans=min(ans,cur-i+1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

