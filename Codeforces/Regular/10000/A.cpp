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
int t,x,y,n;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&x,&y,&n);
        int d=y-x;
        if(d<1LL*n*(n-1)/2) {puts("-1"); continue;}
        vector<int> v;
        v.push_back(y);
        int dd=1,now=y;
        for(int i=1;i<=n-2;i++){
            now-=dd;
            v.push_back(now);
            dd++;
        }
        v.push_back(x);
        reverse(v.begin(),v.end());
        for(auto x:v) printf("%d ",x);
        printf("\n");
    }
    return 0;
}

