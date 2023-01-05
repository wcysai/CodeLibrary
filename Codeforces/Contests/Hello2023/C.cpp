#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ll s=0;
        int ans=0;
        priority_queue<int> pque;
        for(int i=m+1;i<=n;i++){
            s+=a[i];
            if(a[i]<0) pque.push(-a[i]);
            while(s<0){
                int x=pque.top(); pque.pop();
                s+=2*x; ans++;
            }
        }
        while(pque.size()) pque.pop();
        s=0;
        for(int i=m-1;i>=1;i--){
            if(a[i+1]>0) pque.push(a[i+1]);
            s-=a[i+1];
            while(s<0){
                int x=pque.top(); pque.pop();
                s+=2*x; ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

