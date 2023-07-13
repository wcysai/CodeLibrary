#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
ll m;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> v;
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            v.push_back(n-x);
        }
        sort(v.begin(),v.end(),greater<int>());
        scanf("%d",&m);
        int cnt=0,tmp=m;
        if(tmp){
            for(int j=0;j<(int)v.size();j++){
                cnt++;
                tmp-=v[j];
                if(tmp<=0) break;
            }
        }
        printf("%d\n",m-cnt);
    }
    return 0;
}

