#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],pos[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); pos[a[i]]=i;}
        if(pos[2]<pos[1]&&pos[1]<pos[n]) printf("%d %d\n",pos[1],pos[n]);
        else if(pos[2]<pos[n]&&pos[n]<pos[1]) printf("%d %d\n",1,1);
        else if(pos[n]<pos[1]&&pos[1]<pos[2]) printf("%d %d\n",pos[1],pos[n]);
        else if(pos[n]<pos[2]&&pos[2]<pos[1]) printf("%d %d\n",pos[2],pos[n]);
        else if(pos[1]<pos[2]&&pos[2]<pos[n]) printf("%d %d\n",pos[2],pos[n]);
        else if(pos[1]<pos[n]&&pos[n]<pos[2]) printf("%d %d\n",1,1);
    }
    return 0;
}
