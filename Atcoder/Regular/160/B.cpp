#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        int ans=0;
        for(int y=1;y*y<=N;y++){
            //x: [1,y]
            //z: [y,N/y]
            add(ans,6LL*(y-1)*(N/y-y)%MOD);
            add(ans,3LL*(N/y-y)%MOD);
            add(ans,3LL*(y-1)%MOD);
            add(ans,1);
        }
        printf("%d\n",ans);
    }
    return 0;
}

