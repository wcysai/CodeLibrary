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
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> v;
        while(n>1){
            if(n%2==0) break;
            if(((n+1)/2)&1){
                v.push_back(1);
                n=(n+1)/2;
            }
            else{
                v.push_back(2);
                n=(n-1)/2;
            }
        }
        if(n!=1) puts("-1");
        else{
            printf("%d\n",(int)v.size());
            reverse(v.begin(),v.end());
            for(auto x:v) printf("%d ",x);
            puts("");
        }
    }
    return 0;
}

