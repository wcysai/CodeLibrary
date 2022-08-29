#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int main()
{
    cin>>n;
    n%=MOD;
    if(n<0) n+=MOD;
    cout<<n<<endl;
    return 0;
}

