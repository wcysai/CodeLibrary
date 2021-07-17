#include<bits/stdc++.h>
#define MAXN 4005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,a[MAXN];
pair<ll,int> dp[MAXN][MAXN];
int opt[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {dp[i][i]=P(a[i],1); opt[i][i]=i;} 
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            for(int k=opt[i][j-1];k<=opt[]
        }
    }

}