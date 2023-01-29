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
string str;
int main()
{
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>str;
        if(str[0]=='F') cnt++;
    }
    if(cnt*2>n) puts("Yes"); else puts("No");
    return 0;
}

