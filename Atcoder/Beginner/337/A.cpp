#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main(){
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        s+=x; s-=y;
    }
    if(s>0) puts("Takahashi"); else if(s<0) puts("Aoki"); else puts("Draw");
    return 0;
}

