#include<bits/stdc++.h>
#define MAXN 45005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int T;
ll m;
vector<P> v;
ll dp[105][105];
int main()
{
    dp[0][0]=1;
    for(int i=1;i<=100;i++)
    {
        dp[i][0]=dp[i][i]=1;
        for(int j=1;j<i;j++) dp[i][j]=min(INF,dp[i-1][j-1]+dp[i-1][j]);
    }
    scanf("%d",&T);
    while(T--)
    {
        v.clear();
        scanf("%lld",&m);
        v.push_back(P(m,1)); v.push_back(P(m,m-1)); 
        int l=2,r=1000000000;
        while(r-l>1)
        {
            int mid=(l+r)/2;
           if(1LL*mid*(mid-1)<=2*m) l=mid; else r=mid;
        }
        if(1LL*l*(l-1)==2*m) {v.push_back(P(l,2)); v.push_back(P(l,l-2));}
        ll need=2*m,fact=2;
        for(int k=3;k<=5;k++)
        {
            need=need*k;
            fact=fact*k;
            ll tmp=fact;
            for(int i=k;i<=m;i++)
            {
                if(tmp>=m*fact)
                {
                    if(tmp==m*fact)
                    {
                        v.push_back(P(i,k));
                        v.push_back(P(i,i-k));
                    }
                    break;
                }
                tmp/=(i-k+1); tmp*=(i+1);
            }
        }
        for(int i=1;i<=100;i++)
            for(int j=0;j<=i;j++)
                if(dp[i][j]==m) v.push_back(P(i,j));
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        printf("%d\n",(int)v.size());
        for(auto p:v) printf("(%lld,%lld) ",p.F,p.S);
        puts("");
    }
    return 0;
}