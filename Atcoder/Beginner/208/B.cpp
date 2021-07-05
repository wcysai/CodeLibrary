#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int fact[11];
int main()
{
    fact[0]=1;
    for(int i=1;i<=10;i++) fact[i]=fact[i-1]*i;
    int x;
    scanf("%d",&x);
    int ans=0;
    for(int i=10;i>=1;i--)
    {
        ans+=x/fact[i];
        x%=fact[i];
    }
    printf("%d\n",ans);
}