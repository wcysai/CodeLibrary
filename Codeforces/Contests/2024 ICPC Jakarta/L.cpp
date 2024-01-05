#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main(){
    scanf("%d%d",&n,&k);
    if(k<n/2||k>n-1) {puts("-1"); return 0;}
    int num=n/2;
    int excess=k-num;
    for(int i=0;i<(excess)/2;i++) printf("()");
    for(int i=0;i<num-excess;i++) printf("(");
    for(int i=0;i<num-excess;i++) printf(")");
    for(int i=0;i<(excess+1)/2;i++) printf("()");
    printf("\n");
    return 0;
}

