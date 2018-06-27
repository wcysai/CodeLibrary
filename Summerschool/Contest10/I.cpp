#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef multiset<int> SET_INT;
P a[MAXN];
SET_INT s;
int n,t;
bool cmp(P x,P y)
{
    if(x.first!=y.first) return x.first<y.first;
    else return x.second<y.second;
}
int main()
{
    scanf("%d",&t);

    while(t--)
    {
        s.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i].first,&a[i].second);
        sort(a,a+n,cmp);
        s.insert(a[0].second);
        ll ans=a[0].second-a[0].first;
        for(int i=1;i<n;i++)
        {
            int x=*s.rbegin(),y=*s.begin();
            if(a[i].first>=x)
            {
                s.erase(x);
                ans+=a[i].second-x;
                s.insert(a[i].second);
            }
            else if(a[i].first<y)
            {
                s.insert(a[i].second);
                ans+=a[i].second-a[i].first;
            }
            else
            {
                SET_INT::iterator p=s.upper_bound(a[i].first);
                p--;
                ans+=a[i].second-*p;
                s.erase(p);
                s.insert(a[i].second);
            }
        }
        printf("%d %I64d\n",s.size(),ans);
    }
    return 0;
}
