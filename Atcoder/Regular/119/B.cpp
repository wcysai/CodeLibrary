#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
vector<int> v1,v2;
int main()
{
    scanf("%d",&n);
    cin>>s; cin>>t;
    for(int i=0;i<n;i++) if(s[i]=='0') v1.push_back(i);
    for(int i=0;i<n;i++) if(t[i]=='0') v2.push_back(i);
    if(v1.size()!=v2.size()) {puts("-1"); return 0;}
    int ans=0;
    for(int i=0;i<(int)v1.size();i++) if(v1[i]!=v2[i]) ans++;
    printf("%d\n",ans);
    return 0;
}