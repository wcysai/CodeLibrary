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
    for(int i=0;i<n;i++) if(i%3==2) printf("x"); else printf("o");
    printf("\n");
    return 0;
}

