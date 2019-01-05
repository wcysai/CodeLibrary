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
string str;
string a,b,c,d,e;
int main()
{
    cin>>str;
    cin>>a>>b>>c>>d>>e;
    if(str[0]==a[0]||str[0]==b[0]||str[0]==c[0]||str[0]==d[0]||str[0]==e[0]) {puts("YES"); return 0;}
if(str[1]==a[1]||str[1]==b[1]||str[1]==c[1]||str[1]==d[1]||str[1]==e[1]) {puts("YES"); return 0;}
puts("NO");
    return 0;
}

