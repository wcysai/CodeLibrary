#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define KKK 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
mt19937_64 wcy(time(NULL));
int main()
{
    n=5; m=5; q=10;
    printf("%d %d %d\n",n,m,q);
    for(int i=2;i<=n;i++){
        int fa=wcy()%(i-1)+1;
        printf("%d %d\n",fa,i);
    }
    for(int i=0;i<m;i++){
        int id=wcy()%(n-1)+1;
        int val=wcy()%INF+1;
        printf("%d %d\n",id,val);
    }
    for(int i=0;i<q;i++){
        int s=wcy()%n+1,t=wcy()%n+1;
        while(s==t) t=wcy()%n+1;
        int x=wcy()%2;
        ll y=wcy()%(100+1);
        printf("%d %d %d %lld\n",s,t,x,y);
    }
    return 0;
}

