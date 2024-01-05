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
int t,n;
char a[MAXN],b[MAXN];
int reduce(vector<int> &v){
    if(!v.size()) return 0;
    reverse(v.begin(),v.end());
    while(v.size()>1){
        int x=v.back(); v.pop_back();
        int y=v.back(); v.pop_back();
        if(y==x+1){
            v.push_back(1);
            continue;
        }
        else{
            v.push_back(y-x);
            continue;
        }
    }
    int x=v[0];
    return min(x,n+1-x);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> v1,v2;
        scanf("%s",a+1); scanf("%s",b+1);
        for(int i=1;i<=n;i++) if(a[i]=='1') v1.push_back(i);
        for(int i=1;i<=n;i++) if(b[i]=='1') v2.push_back(i);
        if(reduce(v1)==reduce(v2)) puts("YES"); else puts("NO");
    }
    return 0;
}

