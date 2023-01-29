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
int n,m,a[MAXN];
string s[MAXN],t[MAXN];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=m;i++) cin>>t[i];
    int res=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++) if(s[i].substr(3,3)==t[j]) cnt++;
        if(cnt) res++;
    }
    printf("%d\n",res);
    return 0;
}

