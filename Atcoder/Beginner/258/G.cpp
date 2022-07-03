#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3000
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
typedef bitset<3000> bs;
bs b[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        b[i].reset();
        for(int j=i+1;j<n;j++)
            if(str[j]=='1') b[i].set(j);
    }
    ll ans=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(b[i].test(j)) ans+=(b[i]&b[j]).count();
    printf("%lld\n",ans);
    return 0;
}

