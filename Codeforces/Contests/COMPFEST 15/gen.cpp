#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
mt19937 wcy(time(NULL));
int main(){
    scanf("%d",&n);
    printf("%d\n",n);
    q=100000;
    for(int i=2;i<=n;i++){
        int fa=wcy()%(i-1)+1;
        int w=wcy()%INF+1;
        printf("%d %d %d\n",fa,i,w);
    }
    printf("%d\n",q);
    for(int i=0;i<q;i++){
        int x,y;
        x=wcy()%n+1; y=1;
        printf("%d %d\n",x,y);
    }
    return 0;
}

