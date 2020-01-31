#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN],ans;
vector<int> v;
void dfs(vector<int> &v)
{
    int n=(int)v.size();
    if(n==1)
    {
        ans=min(ans,v[0]);
        return;
    }
    else
    {
        vector<int> vv;
        for(int op=0;op<3;op++)
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                {
                    vv.clear();
                    for(int k=0;k<n;k++)
                    {
                        if(k==i||k==j) continue;
                        vv.push_back(v[k]);
                    }
                    if(op==0) vv.push_back(v[i]+v[j]);
                    else if(op==1) vv.push_back(max(v[i]-v[j],v[j]-v[i]));
                    else vv.push_back(v[i]*v[j]);
                    dfs(vv);
                }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n>5)
        {
            puts("0");
            continue;
        }
        else
        {
            ans=INF;
            v.clear();
            for(int i=1;i<=n;i++) v.push_back(a[i]);
            dfs(v);
            printf("%d\n",ans);
        }
    }
    return 0;
}