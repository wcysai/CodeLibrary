#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l[MAXN],r[MAXN],k[MAXN];
vector<pair<int,int> > v1,v2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v1.clear(); v2.clear();
        ll ans=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d%d%d",&k[i],&l[i],&r[i]);
            if(l[i]>=r[i])
            {
                ans+=r[i];
                v1.push_back(P(k[i],l[i]-r[i]));
            }
            else
            {
                ans+=l[i];
                v2.push_back(P(n-k[i],r[i]-l[i]));
            }
        }
        sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
        priority_queue<int,vector<int>,greater<int> > pque;
        for(auto p:v1)
        {
            pque.push(p.S);
            while(pque.size()>p.F)
                pque.pop();
        }
        while(pque.size()) {ans+=pque.top(); pque.pop();}
        for(auto p:v2)
        {
            pque.push(p.S);
            while(pque.size()>p.F)
                pque.pop();
        }
        while(pque.size()) {ans+=pque.top(); pque.pop();}
        printf("%lld\n",ans);
    }
    return 0;
}