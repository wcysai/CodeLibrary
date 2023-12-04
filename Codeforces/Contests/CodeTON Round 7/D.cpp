#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 19
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,a[MAXN];
int bit[MAXN+1];
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
int bisearch(int v){
    int sum=0,pos=0;
    for(int i=MAXLOGN;i>=0;i--)
    {
        if(pos+(1<<i)<=n&&sum+bit[pos+(1<<i)]<v)
        {
            sum+=bit[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        int ss=0;
        set<int> one;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) bit[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ss+=a[i];
            if(a[i]==1) one.insert(i);
            add(i,a[i]);
        }
        for(int i=0;i<q;i++){
            int op,s,x,y;
            scanf("%d",&op);
            if(op==1){
                scanf("%d",&s);
                if(s>ss){
                    printf("NO\n"); continue;
                }
                int pos=bisearch(s);
                if(sum(pos)==s) printf("YES\n");
                else{
                    auto nxt=one.lower_bound(pos);
                    auto tt=one.lower_bound(1);
                    if(tt==one.end()) {printf("NO\n"); continue;}
                    if(nxt!=one.end()) {printf("YES\n"); continue;}
                    //printf("pos=%d tt=%d\n",pos,*tt);
                    if((*tt)<=n-pos+1) printf("YES\n"); else printf("NO\n");
                }
            }
            else{
                scanf("%d%d",&x,&y);
                ss-=a[x];
                add(x,-a[x]);
                if(a[x]==1) one.erase(x);
                a[x]=y;
                if(a[x]==1) one.insert(x);
                add(x,a[x]);
                ss+=a[x];
            }
        }
    }
    return 0;
}

