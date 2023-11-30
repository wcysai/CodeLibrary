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
int n,k,a[MAXN];
string s;
int main()
{
    cin>>s;
    if(s=="ACE"||s=="BDF"||s=="CEG"||s=="DFA"||s=="EGB"||s=="FAC"||s=="GBD") cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

