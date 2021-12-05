#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,k;
string s,t;
int main()
{
    scanf("%d",&k);
    cin>>s; cin>>t;
    a=0; b=0;
    for(int i=0;i<(int)s.size();i++) a=a*k+(s[i]-'0');
    for(int i=0;i<(int)t.size();i++) b=b*k+(t[i]-'0');
    printf("%lld\n",1LL*a*b);
    return 0;
}