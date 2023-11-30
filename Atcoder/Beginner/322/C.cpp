#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
bool has[MAXN];
int ans[MAXN];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i]; has[a[i]]=true;
    }
    for(int i=n;i>=1;i--){
        if(has[i]) ans[i]=0; else ans[i]=ans[i+1]+1;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

