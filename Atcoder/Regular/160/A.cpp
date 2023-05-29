#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 7005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int l,r;
void solve(int cur,int k){
    int num=(n-cur+1)*(n-cur)/2;
    vector<P> v1,v2;
    for(int i=cur+1;i<=n;i++){
        if(a[i]>a[cur]) v2.push_back(P(a[i],i));
        else v1.push_back(P(a[i],i));
    }
    if(k<=(int)v1.size()){
        sort(v1.begin(),v1.end());
        l=cur; r=v1[k-1].S;
        return;
    }
    else if(k>=num-(int)v2.size()+1){
        k-=(num-(int)v2.size());
        sort(v2.begin(),v2.end());
        l=cur; r=v2[k-1].S;
    }
    else{
        solve(cur+1,k-(int)v1.size());
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int x=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j]) x++;
    if(k>x&&k<=x+n){
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        printf("\n");
        return 0;
    }
    if(k>x) k-=n;
    solve(1,k);
    reverse(a+l,a+r+1);
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

