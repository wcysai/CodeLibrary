#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t,k,a[MAXN];
int main(){
    scanf("%d%d",&n,&t);
    vector<int> v;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); v.push_back(a[i]%t);}
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int ans=t;
    for(int i=0;i<(int)v.size()-1;i++) ans=min(ans,t-(v[i+1]-v[i]));
    ans=min(ans,v.back()-v[0]);
    printf("%d\n",(ans+1)/2);
    return 0;
}

