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
int t;
string str;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>str;
        cout<<str;
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    return 0;
}

