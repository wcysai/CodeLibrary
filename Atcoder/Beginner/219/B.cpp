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
string s[3],t;
int main()
{
    cin>>s[0]>>s[1]>>s[2]>>t;
    string res="";
    for(int i=0;i<(int)t.size();i++) res+=s[t[i]-'1'];
    cout<<res<<endl;
    return 0;
}