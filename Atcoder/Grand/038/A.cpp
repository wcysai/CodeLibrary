#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,A,B;
int main()
{
    scanf("%d%d%d%d",&n,&m,&A,&B);
    for(int i=1;i<=B;i++)
    {
        for(int j=1;j<=m;j++) printf("%d",j<=A?0:1);
        puts("");
    }
    for(int i=B+1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) printf("%d",j<=A?1:0);
        puts("");
    }
}
