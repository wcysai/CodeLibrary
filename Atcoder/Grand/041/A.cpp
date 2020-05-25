#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,A,B;
int main()
{
    scanf("%lld%lld%lld",&N,&A,&B);
    if(A>B) swap(A,B);
    if((B-A)%2==0) printf("%lld\n",(B-A)/2);
    else printf("%lld\n",(B-A+1)/2+min(A-1,N-B));
    return 0;
}