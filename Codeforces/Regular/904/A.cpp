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
int t,x,k,a[MAXN];
int calc(int x){
    int sum=0;
    while(x){
        sum+=x%10; x/=10;
    }
    return sum;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&k);
        for(int i=x;;i++){
            if(calc(i)%k==0) {printf("%d\n",i); break;}
        }
    }
    return 0;
}

