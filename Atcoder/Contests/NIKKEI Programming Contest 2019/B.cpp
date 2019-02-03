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
string a,b,c;
int main()
{
    scanf("%d",&n);
    cin>>a;cin>>b;cin>>c;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]&&b[i]==c[i]) continue;
        else if(a[i]==b[i]||a[i]==c[i]||b[i]==c[i]) ans++;
        else ans+=2;
    }
    printf("%d\n",ans);
    return 0;
}

