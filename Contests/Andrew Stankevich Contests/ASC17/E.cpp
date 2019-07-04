#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
char mp[MAXN][MAXN];
bitset<1000> bs[MAXN];
vector<P> v;
int n,ans[MAXN];
int main()
{
    freopen("relations.in","r",stdin);
    freopen("relations.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(mp[i][j]=='0') bs[j].set(i);
    bool flag=true;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            bitset<1000> tmp=bs[i]&bs[j];
            if((tmp^bs[i]).count()&&(tmp^bs[j]).count()) flag=false;
        }
    if(!flag) {puts("NO"); return 0;}
    puts("YES");
    for(int i=0;i<n;i++) v.push_back(P(bs[i].count(),i));
    sort(v.begin(),v.end());
    int tot=0;
    for(int i=n-1;i>=0;i--) ans[v[i].S]=tot++;
    for(int i=0;i<n;i++)
    {
        int res=n;
        for(int j=0;j<n;j++) if(mp[i][j]=='1') res=min(res,ans[j]);
        printf("%d ",res);
    }
    puts("");
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}
