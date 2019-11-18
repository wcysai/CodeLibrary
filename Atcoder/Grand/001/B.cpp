#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,X;
ll solve(ll N,ll X)
{
    if(X==0) return 0;
    if(X*2==N) return 3*X;
    if(X*2<N)
    {
        ll rem=N%X,cnt=(N-X)/X;
        if(rem==0) rem+=X,cnt--;
        return cnt*3*X+solve(rem+X,X);
    }
    else
    {
        ll rem=X%(N-X),cnt=X/(N-X);
        if(rem==0) rem+=N-X,cnt--;
        return 3*(N-X)*cnt+solve(rem+(N-X),rem);
    }
}
int main()
{
    scanf("%lld%lld",&N,&X);
    printf("%lld\n",solve(N,X));
    return 0;
}
