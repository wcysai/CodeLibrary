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
int t,n,k,a[MAXN],pos[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        if(n==1) {puts("0"); continue;}
        int l,r,vl,vr,ans;
        ans=n/2;
        if(n&1){
            vl=vr=pos[(n+1)/2],l=(n+1)/2-1,r=(n+1)/2+1;
        }
        else{
            vl=INF,vr=-INF,l=n/2,r=n/2+1;
        }
        while(l>=1){
            if(pos[l]<=pos[r]&&pos[l]<=vl&&pos[r]>=vr){
                ans--; vl=pos[l]; vr=pos[r]; l--; r++;
            }
            else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

