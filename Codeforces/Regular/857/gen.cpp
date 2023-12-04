#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000006
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int l[MAXN],r[MAXN];
mt19937 wcy(time(NULL));
int main(){
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=2;i<=n;i++){
        int p=wcy()%(i-1)+1;
        printf("%d ",p);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        int l=wcy()%MOD+1,r=wcy()%MOD+1;
        if(l>r) swap(l,r);
        printf("%d %d\n",l,r);
    }
    int m=10;
    printf("%d\n",m);
    for(int i=0;)
    return 0;
}

