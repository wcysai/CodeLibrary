#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    if(str[n-1]=='o') puts("Yes"); else puts("No");
    return 0;
}