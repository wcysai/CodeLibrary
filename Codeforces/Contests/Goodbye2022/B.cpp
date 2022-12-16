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
int t,n,k,a[2][MAXN],b[2][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&b[i][j]);
        bool f=true;
        for(int i=1;2*i-1<=n;i++)
        {
            multiset<int> s1,s2;
            s1.insert(a[0][i]); s1.insert(a[1][i]); s1.insert(a[0][n+1-i]); s1.insert(a[1][n+1-i]);
            s2.insert(b[0][i]); s2.insert(b[1][i]); s2.insert(b[0][n+1-i]); s2.insert(b[1][n+1-i]);
            if(s1!=s2) {f=false; break;}
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

