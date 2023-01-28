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
int t,l,r;
int res[MAXN];
int f(int x){
    if(x==1) return 0;
    else if(x&1) return f(x/2);
    else return f(x/2)+1;
}
int g(int x){
    if(x==1) return 1;
    else if(x&1) return 2*g(x/2);
    else return 2*g(x/2)+1;
}
int solve(int l,int r,int x,int y){
    if(l>r) return 0;
    if(l==r) return x*f(l)+y*g(l);
    if(l&1) return max(x*f(l)+y*g(l),solve(l+1,r,x,y));
    if(r%2==0) return max(x*f(r)+y*g(r),solve(l,r-1,x,y));
    return solve(l/2,r/2,x,y*2)+x+y;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&r);
        printf("%d\n",solve(l,r,1,1));
    }
    return 0;
}

