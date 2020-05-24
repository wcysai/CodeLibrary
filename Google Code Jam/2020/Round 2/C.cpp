#include<bits/stdc++.h>
#define MAXN 105
#define INF 200000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
int n,ans;
P p[MAXN];
int pre[MAXN];
vector<ll> v;
void solve(vector<int> &a)
{
    int sum=0,single=0;
    for(auto x:a) if(x==1) single++; else sum+=x;
    if(sum&1) ans=max(ans,sum+min(1,single));
    else ans=max(ans,sum+min(2,single));
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        ans=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].F,&p[i].S);
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                v.clear();
                int dx=p[j].F-p[i].F,dy=p[j].S-p[i].S;
                for(int k=1;k<=n;k++) 
                {
                    int x=p[k].F,y=p[k].S;
                    v.push_back(1LL*y*dx-1LL*x*dy);
                }
                sort(v.begin(),v.end());
                vector<int> tmp;
                int cnt=0;
                for(int i=0;i<n;i++)
                {
                    if(i==0||v[i]!=v[i-1])
                    {
                        if(cnt>0) tmp.push_back(cnt);
                        cnt=1;
                    } 
                    else cnt++;
                }
                if(cnt) tmp.push_back(cnt);
                solve(tmp);
            }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}