#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,r,c,a[MAXN];
int sg[MAXN][MAXN];
int calc(int x,int y){
    if(x==0||y==0) return 0;
    if(x<y) swap(x,y);
    int r=x%y,num=x/y;
    return calc(r,y)^(num&1);
}
int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++){
        int r,c;
        scanf("%d%d",&r,&c);
        ans^=calc(r,c); ans^=calc(r-1,c); ans^=calc(r,c-1); ans^=calc(r-1,c-1);
    }
    if(ans) printf("FIRST\n"); else printf("SECOND\n");
    return 0;
}

