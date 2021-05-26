#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str[MAXN];
int cntb[MAXN],cntr[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) cin>>str[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cntb[i+j]+=(str[i][j]=='B');
            cntr[i+j]+=(str[i][j]=='R');
        }
    int ans=1;
    for(int i=0;i<n+m-1;i++)
    {
        if(cntb[i]&&cntr[i]) {ans=0; break;}
        if(!cntb[i]&&!cntr[i]) ans=2LL*ans%MOD;
    }
    printf("%d\n",ans);
    return 0;
}