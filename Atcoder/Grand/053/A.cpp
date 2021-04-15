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
int a[MAXN],t[MAXN];
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);
    t[0]=0;
    for(int i=0;i<n;i++) if(str[i]=='<') t[i+1]=t[i]+1; else t[i+1]=t[i]-1;
    int mini=INF;
    for(int i=0;i<=n;i++) mini=min(mini,t[i]);
    for(int i=0;i<=n;i++) t[i]-=mini;
    int ans=INF;
    for(int i=0;i<=n;i++)
    {
        if(i!=n) ans=min(ans,max(a[i+1]-a[i],a[i]-a[i+1]));
        if(t[i]!=0) ans=min(ans,a[i]/t[i]);
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans-1;i++)
    {
        for(int j=0;j<=n;j++) a[j]-=t[j];
        for(int j=0;j<=n;j++) printf("%d%c",t[j],j==n?'\n':' ');
    }
    for(int j=0;j<=n;j++) printf("%d%c",a[j],j==n?'\n':' ');
    return 0;
}