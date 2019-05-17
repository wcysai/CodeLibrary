#include<bits/stdc++.h>
#define MAXN 1505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
const int base=INF;
const int base_digits=9;
struct bigint
{
    vector<int> a;
    bigint operator+(const bigint &v) const
    {
        bigint res=v;
        for(int i=0,carry=0;i<(int)max(a.size(),v.a.size())||carry;++i)
        {
            if(i==(int)res.a.size()) res.a.push_back(0);
            res.a[i]+=carry+(i<(int)a.size()?a[i]:0);
            carry=res.a[i]>=base;
            if(carry) res.a[i]-=base;
        }
        return res;
    }
    friend ostream& operator<<(ostream &stream,const bigint &v)
    {
        stream<<(v.a.empty()?0:v.a.back());
        for(int i=(int)v.a.size()-2;i>=0;i--) stream<<setw(base_digits)<<setfill('0')<<v.a[i];
        return stream;
    }
};
bigint dp[MAXN][MAXN];
int main()
{
    freopen("sweets.in","r",stdin);
    freopen("sweets.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            dp[i][j].a.clear();
    dp[1][1].a.push_back(1);
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j-1];
            if(i>=2*j) dp[i][j]=dp[i][j]+dp[i-j][j];
        }
    cout<<dp[n][k]<<endl;
    return 0;
}
