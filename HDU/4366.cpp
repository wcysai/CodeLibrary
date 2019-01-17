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
int n;
double p[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++) scanf("%lf",&p[i]);
        double ans=0;
        for(int mask=1;mask<(1<<n);mask++)
        {
            int cnt=0; double res=0;
            for(int j=0;j<n;j++) 
                if(mask&(1<<j)) {cnt++; res+=p[j];}
            if(cnt&1) ans+=1.0/res; else ans-=1.0/res;
        }
        printf("%.10f\n",ans);
    }
    return 0;
}

