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
int main(){
    n=(1<<22);
    printf("%d\n",1);
    printf("%d %d\n",n,1000000);
    for(int i=0;i<1000000;i++){
        int x=wcy()%n;
        printf("%d ",x);
        printf("\n");
    }
    return 0;
}

