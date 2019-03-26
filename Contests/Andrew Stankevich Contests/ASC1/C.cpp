#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,fa[MAXN];
bool used[MAXN];
vector<int> ans;
int main()
{
    freopen("grant.in","r",stdin);
    freopen("grant.out","w",stdout);
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        fa[i]=x;
    }
    memset(used,false,sizeof(used));
    for(int i=n;i>=2;i--)
    {
        if(used[i]) continue;
        if(used[fa[i]]) continue;
        used[i]=used[fa[i]]=true;
        ans.push_back(i);
    }
    reverse(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size()*1000);
    for(auto v:ans) printf("%d ",v);
}
