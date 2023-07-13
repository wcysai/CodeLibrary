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
/*
int dp[(1<<16)];
int solve(int mask){
    if(mask&1) return solve(mask^1);
    if(mask==0) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int ans=0;
    for(int i=0;i<4;i++){
        bool f=false;
        for(int j=(1<<i);j<(1<<(i+1));j++) if(mask&(1<<j)) f=true;
        if(f){
            for(int j=(1<<i);j<(1<<(i+1));j++){
                int nmask=0;
                for(int k=1;k<=15;k++){
                    if(!(mask&(1<<k))) continue;
                    int z=min(k,k^j);
                    nmask|=(1<<z);
                }
                assert(nmask<mask);
                if(!solve(nmask)) ans=1;
            }
        }
    }
    return dp[mask]=ans;
}
*/
int main()
{
    return 0;
}

