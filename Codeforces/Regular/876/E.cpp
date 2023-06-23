#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
bitset<1000000> dp[MAXN];
int color[MAXN];
void second(){
    int x; scanf("%d",&x);
    if(x==0||x==-1) exit(0);
    int id=-1;
    for(int i=1;i<=n;i++){
        if(a[i]>0&&color[i]!=color[x]){
            id=i; break;
        }
    }
    assert(id!=-1);
    printf("%d\n",id); fflush(stdout);
    int d=min(a[id],a[x]); a[id]-=d; a[x]-=d;
}
void first(){
    int id=-1;
    for(int i=1;i<=n;i++){
        if(a[i]>0&&(id==-1||a[i]<a[id])){
            id=i; 
        }
    }
    assert(id!=-1);
    printf("%d\n",id); fflush(stdout);
    int x; scanf("%d",&x);
    if(x==0||x==-1) exit(0);
    int d=min(a[id],a[x]); a[id]-=d; a[x]-=d;
}
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); sum+=a[i];}
    dp[0].set(0);
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i-1]<<a[i])|dp[i-1];
    }
    if((sum%2==0)&&(dp[n].test(sum/2))){
        printf("Second\n");
        fflush(stdout);
        int now=sum/2;
        for(int i=n;i>=1;i--){
            if(now>=a[i]&&dp[i-1].test(now-a[i])) {color[i]=1; now-=a[i];}
            else color[i]=0;
        }
        while(true) second();
    }
    else{
        printf("First\n");
        fflush(stdout);
        while(true) first();
    }
    return 0;
}

