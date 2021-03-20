#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],a[MAXN*MAXN];
int mark[MAXN*MAXN];
int need[MAXN];
vector<P> v;
vector<P> spare;
bool cmp(P p,P q)
{
    return x[p.F]>x[q.F];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&x[i]);
        mark[x[i]]=i;
        need[i]=i-1;
        v.push_back(P(i,i-1));
    }
    bool f=true;
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<=n*n;i++)
    {
        if(mark[i])
        {
            int val=mark[i];
            if(need[val])
            {
                f=false;
                break;
            }
            a[i]=val;
            spare.push_back(P(val,n-val));
        }
        else
        {
            while(v.size()&&v.back().S==0) v.pop_back();
            if(!v.size())
            {
                while(spare.size()&&spare.back().S==0) spare.pop_back();
                if(!spare.size()) {f=false; break;}
                P &p=spare.back();
                a[i]=p.F;
                p.S--; 
            }
            else
            {
                P &p=v.back();
                a[i]=p.F;
                p.S--; need[p.F]--;
            }
        }
    }
    if(!f) puts("No");
    else
    {
        puts("Yes");
        for(int i=1;i<=n*n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}