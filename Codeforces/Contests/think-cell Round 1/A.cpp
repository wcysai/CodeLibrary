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
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
        sort(a+1,a+2*n+1);
        int sum=0;
        for(int i=1;i<=2*n;i+=2) sum+=a[i];
        printf("%d\n",sum);
    }
    return 0;
}

