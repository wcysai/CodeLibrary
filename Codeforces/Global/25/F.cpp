#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN],num[MAXN],q[MAXN];
ll k;
int t,bit[MAXN];
bool used[MAXN];
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) bit[i]=0,used[i]=false;
        ll inv=0;
        for(int i=1;i<=n;i++){
            num[i]=n-p[i]-(i-1-sum(p[i]));
            inv+=n-i-num[i];
            add(p[i],1);
            q[i]=-1;
        }
        //printf("inv=%lld\n",inv);
        ll l=inv,r=1LL*n*(n-1)-inv;
        if(k<l||k>r||((k+inv)&1)){
            puts("NO");
            continue;
        }
        puts("YES");
        ll need=(k-inv)/2;
        int now=1;
        for(int i=1;i<=n;i++){
            if(!need){
                while(used[now]) now++;
                q[p[i]]=now; used[now]=true;
                continue;
            }
            if(need>=num[i]){
                q[p[i]]=n-i+1; used[n-i+1]=true;
                need-=num[i];
            }
            else{
                int nxt=1;
                for(int j=i+1;j<=n;j++) {
                    nxt++;
                    if(p[j]>p[i]) need--;
                    if(!need) break;
                }
                q[p[i]]=nxt; used[nxt]=true;
            }
        }
        for(int i=1;i<=n;i++) printf("%d%c",q[i],i==n?'\n':' ');
    }
    return 0;
}

