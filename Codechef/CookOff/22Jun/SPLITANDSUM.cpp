#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool nonzero()
{
    for(int i=1;i<=n;i++) if(a[i]) return true;
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool f=false;
        while(nonzero())
        {
            int s=0;
            for(int i=1;i<=n;i++) s+=(a[i]&1);
            if(s<=1)
            {
                for(int i=1;i<=n;i++) a[i]/=2;
                continue;
            }
            int last=1;
            vector<P> v;
            for(int i=1;i<=n;i++)
                if(a[i]&1) {v.push_back(P(last,i)); last=i+1;}
            v[v.size()-1].S=n;
            puts("YES");
            printf("%d\n",(int)v.size());
            for(auto p:v) printf("%d %d\n",p.F,p.S);
            f=true; break;
        }
        if(!f) puts("NO");
    }
    return 0;
}

