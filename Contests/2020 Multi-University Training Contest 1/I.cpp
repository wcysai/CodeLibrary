#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
map<P,int> mp;
vector<P> v,vv;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        v.clear(); 
        mp.clear();
        for(int i=1;i<=N;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v.push_back(P(b,a));
            mp[P(b,a)]++;
        }
        sort(v.begin(),v.end());
        vv.clear();
        for(int i=0;i<N;i++)
        {
            while(vv.size()&&vv.back().S<=v[i].S) vv.pop_back();
            vv.push_back(v[i]);
        }
        v.clear();
        swap(v,vv);
        for(int i=0;i<(int)v.size();i++)
        {
            int t=(int)vv.size();
            while(t>1&&1LL*(vv[t-2].S-vv[t-1].S)*(v[i].F-vv[t-1].F)>=1LL*(vv[t-1].S-v[i].S)*(vv[t-1].F-vv[t-2].F)) 
            {
                vv.pop_back();
                t--;
            }
            vv.push_back(v[i]);
        }
        v.clear();
        swap(v,vv);
        for(int i=0;i<(int)v.size();i++) if(mp[v[i]]==1) vv.push_back(v[i]);
        printf("%d\n",(int)vv.size());
    }
    return 0;
}