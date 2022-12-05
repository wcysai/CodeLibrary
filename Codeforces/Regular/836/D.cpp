#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
//4 5 6-> 3 6 7
//5 6 7 8 9->4 6 7 9 10

//4 5->3 6
//5 6 7 8->4 5 7 9
//6 7 8 9 10 11->4 5 6 9 10 12
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n&1)
        {
            for(int i=1;i<=n;i++) a[i]=(n/2)+i+2;
            a[1]--; a[n]++; a[n-1]++;
        }
        else
        {
            for(int i=1;i<=n;i++) a[i]=(n/2)+i+2;
            for(int i=1;i<=n/2;i++) a[i]--;
            a[n]++;
        }
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}

