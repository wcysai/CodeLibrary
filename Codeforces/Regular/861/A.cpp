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
int t,l,r;
int calc(int x){
    vector<int> v;
    while(x){
        v.push_back(x%10);
        x/=10;
    }
    sort(v.begin(),v.end());
    return v.back()-v[0];
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&r);
        int ans=-1,id=-1;
        for(int i=l;i<=r;i++){
            int z=calc(i);
            if(z>ans){
                ans=z;
                id=i;
            }
            if(ans==9) break;
        }
        printf("%d\n",id);
    }
    return 0;
}

