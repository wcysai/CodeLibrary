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
int t,n,k,a[MAXN];
vector<int> res[MAXN];
set<int> ans;
void construct(){
    ans.clear();
    ans.insert(2); ans.insert(3); ans.insert(6);
    for(auto x:ans) res[3].push_back(x); 
    while(ans.size()!=500){
        bool f=false;
        for(auto x:ans){
            int y=x,z=x;
            for(int T=2;T<=30;T++){
                if(x%T!=0) continue;
                y=x*(T+1); z=x*(T+1)/T;
                if(ans.count(y)||ans.count(z)) continue;
            }
            if(ans.count(y)||ans.count(z)) continue;
            f=true; ans.erase(x); ans.insert(y); ans.insert(z); break;
        }
        for(auto x:ans) res[(int)ans.size()].push_back(x); 
    }
}
int main()
{
    scanf("%d",&t);
    construct();
    while(t--){
        scanf("%d",&n);
        if(n==1) printf("Yes\n1\n");
        else if(n==2) printf("No\n");
        else{
            printf("Yes\n");
            for(auto x:res[n]) printf("%d ",x);
            printf("\n");
        }
    }
    return 0;
}

