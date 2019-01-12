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
int n,A,B,a[MAXN];
int main()
{
    scanf("%d%d%d",&n,&A,&B);
    int cnt0,cnt1,cnt2;
    cnt0=cnt1=cnt2=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x<=A) cnt0++; else if(x>B) cnt2++; else cnt1++;
    }
    printf("%d\n",min(min(cnt0,cnt1),cnt2));
    return 0;
}

