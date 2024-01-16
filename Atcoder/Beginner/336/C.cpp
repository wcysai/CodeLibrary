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
int k,a[MAXN];
ll n,pw[MAXN];
int main(){
    scanf("%lld",&n);
    if(n==1) {puts("0"); return 0;}
    pw[0]=1;
    for(int i=1;i<=20;i++) pw[i]=5LL*pw[i-1];
    n--;
    bool flag=false;
    for(int i=20;i>=0;i--){
        if(pw[i]<=n){
            int num=n/pw[i];
            //printf("i=%d num=%d\n",i,num);
            printf("%d",num*2);
            n-=num*pw[i];
            flag=true;
        }
        else if(flag) printf("0");
    }
    printf("\n");
    return 0;
}

