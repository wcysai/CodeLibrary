#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int m,n;
int val[MAXN];
int main()
{
    freopen("bandits.in","r",stdin);
    freopen("bandits.out","w",stdout);
    scanf("%d%d",&n,&m);
    val[n]=m;
    for(int i=n-1;i>=1;i--)
    {
        vector<P> v; v.clear();
        for(int j=i+1;j<=n;j++) v.push_back(P(val[j]+1,j));
        sort(v.begin(),v.end());
        int need=(n-i+1)/2;
        int sum=0;
        for(int i=0;i<need;i++) sum+=v[i].F;
        if(sum>m) val[i]=-1;
        else
        {
            int last=v[need-1].F;
            bool flag=(need<(int)v.size()&&v[need-1].F==v[need].F);
            for(int j=0;j<need;j++) val[v[j].S]=val[v[j].S]+1;
            for(int j=need;j<(int)v.size();j++) val[v[j].S]=0;
            val[i]=m-sum;
            if(flag)
            {
                for(int j=0;j<(int)v.size();j++) if(v[j].F==last) val[v[j].S]=0;
            }
        }
    }
    printf("%d\n",val[1]);
    return 0;
}
