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
mt19937 wcy(time(NULL));
int u[MAXN],v[MAXN];
int main(){
    int t=200000/24;
    printf("%d\n",t);
    set<P> s;
    for(int i=0;i<t;i++){
        printf("%d %d\n",24,24);
        for(int j=1;j<=23;j++) printf("%d %d\n",j,j+1);
        printf("%d %d\n",24,1);
        for(auto p:s) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

