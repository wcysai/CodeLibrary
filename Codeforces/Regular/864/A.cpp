#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 sadkdisa
#define x1 dskoda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,x1,y1,x2,y2;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int a=4,b=4;
        if(x1==1||x1==n) a--;
        if(y1==1||y1==m) a--;
        if(x2==1||x2==n) b--;
        if(y2==1||y2==m) b--;
        printf("%d\n",min(a,b));
    }
    return 0;
}

