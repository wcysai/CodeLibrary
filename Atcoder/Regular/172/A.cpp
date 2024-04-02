#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w,n,k,a[MAXN];
int cnt[MAXN];
ll num[MAXN];
int main(){
    scanf("%d%d%d",&h,&w,&n);
    int maxi=0;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cnt[a[i]]++; maxi=max(maxi,a[i]);}
    int x=0;
    while(1<<(x+1)<=min(h,w)) x++;
    if(maxi>x) {puts("No"); return 0;}
    ll sum=0;
    for(int i=x;i>=0;i--){
        num[i]=1LL*(h/(1<<i))*(w/(1<<i))-sum;
        sum+=num[i];
        sum*=4;
    }
    ll res=0;
    while(x>=0){
        res+=num[x];
        if(cnt[x]>res){
            puts("No"); return 0;
        }
        res-=cnt[x];
        res*=4;
        x--;
    }
    puts("Yes");
    return 0;
}

