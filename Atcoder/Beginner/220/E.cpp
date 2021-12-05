#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d,p2[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    p2[0]=1;
    for(int i=1;i<=2000000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d%d",&n,&d);
    int num=1,ans=0;
    for(int lcp=1;lcp<=n;lcp++)
    {
        int maxi=n-lcp;
        if(2*maxi<d) break;
        int r=min(d-1,maxi),l=max(1,d-maxi);
        if(l<=r) add(ans,1LL*(r-l+1)*num%MOD*p2[d-2]%MOD);
        if(maxi>=d) add(ans,2LL*num*p2[d-1]%MOD);
        num=2LL*num%MOD;
    }
    printf("%d\n",2LL*ans%MOD);
    return 0;
}