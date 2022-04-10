#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);
    int ans=INF;
    for(int i=0;i<n;i++)
        if(i!=n) ans=min(ans,max(a[i+1]-a[i],a[i]-a[i+1]));
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
        for(int j=0;j<=n;j++) printf("%d%c",(a[j]+i-1)/ans,j==n?'\n':' ');
    return 0;
}