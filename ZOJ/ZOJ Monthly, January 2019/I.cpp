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
int T,N,M,A[MAXN],tot,op;
map<int,int> mp;
set<int> s[MAXN];
multiset<int> ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M); ans.clear(); mp.clear(); tot=0;
        for(int i=1;i<=N;i++) 
        {
            scanf("%d",&A[i]);
            if(mp.find(A[i])==mp.end()) mp[A[i]]=++tot;
            s[mp[A[i]]].insert(i);
        }
        for(int i=1;i<=tot;i++) 
        {
            auto itb=s[i].begin();auto ite=s[i].end(); ite--;
            ans.insert((*ite)-(*itb));
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d",&op);
            if(op==2) 
            {
                auto it=ans.end(); it--;
                if(*it==0) puts("-1"); else printf("%d\n",(*it));
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y); if(A[x]==y) continue;
                int id=mp[A[x]];
                auto itb=s[id].begin(); auto ite=s[id].end(); ite--;
                ans.erase(ans.find((*ite)-(*itb)));
                s[id].erase(x);
                if(s[id].size()!=0)
                {
                    itb=s[id].begin(); ite=s[id].end(); ite--;
                    ans.insert((*ite)-(*itb));
                }
                A[x]=y;
                if(mp.find(y)==mp.end()) mp[y]=++tot;
                id=mp[A[x]];
                if(s[id].size()!=0)
                {
                    itb=s[id].begin(); ite=s[id].end(); ite--;
                    ans.erase(ans.find((*ite)-(*itb)));
                }
                s[id].insert(x);
                itb=s[id].begin(); ite=s[id].end(); ite--;
                ans.insert((*ite)-(*itb));
            }
        }
        for(int i=1;i<=tot;i++) s[i].clear();
    }
    return 0;
}

