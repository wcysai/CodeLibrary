#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
int cnt[MAXN];
int num[MAXN];
int calc(int box,int res){
    return min(box*k,res);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int pos=n,box=0,ans=0;
    for(int i=1;i<=n;i++){
        if(box==m) {pos=i-1; break;}
        if(num[a[i]]%k==0) {
            ans-=calc(num[a[i]]/k,cnt[a[i]]);
            box++;
            ans+=calc(num[a[i]]/k+1,cnt[a[i]]);
        }
        num[a[i]]++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n-1;i++){
        a[i+n]=a[i];
        num[a[i]]--;
        if(num[a[i]]%k==0){
            ans-=calc(num[a[i]]/k+1,cnt[a[i]]);
            box--;
            ans+=calc(num[a[i]]/k,cnt[a[i]]);
        }
        while(pos<n+i&&box<m){
            pos++;
            if(num[a[pos]]%k==0) {
                ans-=calc(num[a[pos]]/k,cnt[a[pos]]);
                box++;
                ans+=calc(num[a[pos]]/k+1,cnt[a[pos]]);
            }
            num[a[pos]]++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

