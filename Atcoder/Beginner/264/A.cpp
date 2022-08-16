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
string str="atcoder";
int main()
{
    int l,r;
    cin>>l>>r;
    cout<<str.substr(l-1,r-l+1)<<endl;
    return 0;
}

