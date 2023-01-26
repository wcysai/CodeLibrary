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
int t,cnt,k,a[MAXN];
int ask(int x){
    printf("- %d\n",x);
    fflush(stdout);
    int z; scanf("%d",&z); assert(z!=-1); 
    return z;
}
void answer(int x){
    printf("! %d\n",x); fflush(stdout);
}
void solve(int cnt){
    int sum=1;
    int z=ask(1),last=z-cnt+1;
    while(z!=last){
        //printf("z=%d last=%d\n",z,last);
        sum+=(1<<last);
        cnt=z-last;
        z=ask((1<<last));
        last=z-cnt+1;
    }
    answer(sum+(1<<z)-1);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&cnt);
        solve(cnt);
    }
    return 0;
}

