#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p,a[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int get_ans(int x){
    int sum=0,cnt=0;
    for(int i=0;i<p;i++){
        if(x%prime[i]==0){
            int t=1;
            while(x%prime[i]==0) {x/=prime[i]; t*=prime[i];}
            sum+=t;
            cnt++;
        }
    }
    if(x>1) {sum+=x; cnt++;}
    if(cnt==1) return INF; else return sum;
}
int main()
{
    p=sieve(100000);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(get_ans(n)<=n) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}

