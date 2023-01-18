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
int t,w,d,h,a,b,f,g;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d%d",&w,&d,&h,&a,&b,&f,&g);
        int ans=a+h+f+max(b-g,g-b);
        ans=min(ans,w-a+h+w-f+max(b-g,g-b));
        ans=min(ans,b+h+g+max(a-f,f-a));
        ans=min(ans,d-b+h+d-g+max(a-f,f-a));
        printf("%d\n",ans);
    }
    return 0;
}

