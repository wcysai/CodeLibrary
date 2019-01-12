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
int H,W,N;
int main()
{
    scanf("%d%d%d",&N,&H,&W);
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i+H-1<=N&&j+W-1<=N) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

