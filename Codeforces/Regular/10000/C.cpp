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
int t,x,n,k,a[MAXN];
vector<int> ans;
void solve(int x,int mult){
    if(x==1) return;
    if(x&1){
        ans.push_back(mult);
        solve(x/2,mult*2);
        ans.push_back(mult);
    }
    else{
        solve(x/2,mult*2);
        ans.push_back(mult);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        ans.clear();
        scanf("%d",&x); solve(x,1);
        printf("%d\n",(int)ans.size()+1);
        int now=x;
        printf("%d",now);
        for(auto x:ans) {
            now-=x;
            printf(" %d",now);
        }
        printf("\n");
    }
    return 0;
}

