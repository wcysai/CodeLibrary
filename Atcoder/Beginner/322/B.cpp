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
int n,m,k,a[MAXN];
string s,t;
int main()
{
    cin>>n>>m;
    cin>>s>>t;
    if(s==t) cout<<0<<endl;
    else if(n>m) cout<<3<<endl;
    else{
        int cnt=0;
        if(t.substr(0,n)==s) cnt++;
        if(t.substr(m-n,n)==s) cnt+=2;
        if(cnt==3) cnt=0; else if(cnt==0) cnt=3;
        cout<<cnt<<endl;
    }
    return 0;
}

