#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN];
bool win[MAXN];
vector<int> winning[27];
string str;
int main()
{
    assert(win[0]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int mask=0;
        for(int j=0;j<(int)str.size();j++) mask|=(1<<((int)str[j]-'a'));
    }
    return 0;
}
