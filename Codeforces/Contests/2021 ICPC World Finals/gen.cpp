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
    int n=200000,m=500000,s=wcy()%n+1;
    printf("%d %d %d\n",n,m,s);
    for(int i=0;i<m;i++) printf("%d %d\n",wcy()%INF+1,wcy()%n+1);
    return 0;
}

