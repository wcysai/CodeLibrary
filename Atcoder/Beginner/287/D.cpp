#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;
int main()
{
    cin>>s>>t;
    int n=(int)s.size(),m=(int)t.size();
    int pre=0,suf=0;
    for(int i=0;i<m;i++){
        if(s[i]=='?'||t[i]=='?'||s[i]==t[i]) pre++;
        else break;
    }
    for(int i=0;i<m;i++){
        if(s[n-1-i]=='?'||t[m-1-i]=='?'||s[n-1-i]==t[m-1-i]) suf++;
        else break;
    }
    for(int i=0;i<=m;i++) if(i<=pre&&m-i<=suf) puts("Yes"); else puts("No");
    return 0;
}

