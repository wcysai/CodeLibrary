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
mt19937 wcy(time(NULL));
int main(){
    int n=2000,q=200000;
    printf("%d %d\n",n,q);
    for(int i=2;i<=n;i++){
        printf("%d %d %d\n",wcy()%(i-1)+1,i,wcy()%INF);
    }
    for(int i=0;i<q;i++){
        int s=wcy()%n+1,t=wcy()%n+1,k=wcy()%n+1;
        printf("%d %d %d\n",s,t,k);
    }
    return 0;
}

