#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n1,m1,n2,m2,a[MAXN][MAXN],b[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n1,&m1);
    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d",&n2,&m2);
    for(int i=0;i<n2;i++)
        for(int j=0;j<m2;j++)
            scanf("%d",&b[i][j]);
    bool f=false;
    for(int mask1=0;mask1<(1<<n1);mask1++)
    {
        if(__builtin_popcount(mask1)!=n1-n2) continue;
        for(int mask2=0;mask2<(1<<m1);mask2++)
        {
            if(__builtin_popcount(mask2)!=m1-m2) continue;
            vector<int> v1,v2;
            for(int i=0;i<n1;i++) if(!(mask1&(1<<i))) v1.push_back(i);
            for(int i=0;i<m1;i++) if(!(mask2&(1<<i))) v2.push_back(i);
            bool flag=true;
            for(int i=0;i<n2;i++)
                for(int j=0;j<m2;j++)
                    if(b[i][j]!=a[v1[i]][v2[j]]) flag=false;
            if(flag) f=true;
        }
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}

