#pragma GCC optimize(3)
#include<iostream>
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
        vector<int> even,odd;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]&1) odd.push_back(i); else even.push_back(i);
        }
        if(odd.size()>=3){
            puts("YES");
            printf("%d %d %d\n",odd[0],odd[1],odd[2]);
        }
        else if(odd.size()&&even.size()>=2){
            puts("YES");
            printf("%d %d %d\n",odd[0],even[0],even[1]);
        }
        else puts("NO");
    }
    return 0;
}

