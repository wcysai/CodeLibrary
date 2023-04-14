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
int t,n,m,k,a[MAXN];
int ask(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int z; scanf("%d",&z);return z;
}
void answer(int x,int y){
    printf("! %d %d\n",x,y);
    fflush(stdout);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int x=ask(1,1);
        int y=ask(min(1+x,n),1);
        int z=ask(1,min(1+x,m));
        if(y==x&&z==x) answer(1+x,1+x);
        else if(y<z) answer(1+x,1+y);
        else answer(1+z,1+x);
    }
    return 0;
}

