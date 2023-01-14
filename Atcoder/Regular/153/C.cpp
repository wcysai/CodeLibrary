#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==1) {puts("Yes"); puts("0"); return 0;}
    if(a[n]!=-1) for(int i=1;i<=n;i++) a[i]=-a[i];
    int id1=-1,id2=-1,s=0;
    for(int i=n;i>=1;i--){
        s+=a[i];
        if(s>0) {id1=i; break;}
    }
    s=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        if(s<0){ id2=i; break;}
    }
    if(id1==-1&&id2==-1) {puts("No"); return 0;}
    ll res=0;
    for(int i=1;i<=n;i++){
        ans[i]=i;
        res+=ans[i]*a[i];
    }
    if(res>0) ans[n]+=res;
    else if(id1!=-1){
        for(int i=id1;i<=n;i++) ans[i]-=res;
    }
    else{
        for(int i=1;i<=id2;i++) ans[i]+=res;
    }
    puts("Yes");
    for(int i=1;i<=n;i++) printf("%lld%c",ans[i],i==n?'\n':' ');
    return 0;
}
