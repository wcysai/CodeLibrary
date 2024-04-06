#include<bits/stdc++.h>
#define MAXN 2000005
#define MAXLOGN 22
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],x[MAXN],y[MAXN];
int bit[MAXN*2];
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
    for(int i=MAXLOGN;i>=0;i--){
        if(pos+(1<<i)<=n&&sum+bit[pos+(1<<i)]<v){
            sum+=bit[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) add(i,1);
    for(int i=1;i<=n/2;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n/2;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n/2;i++){
        x[i]=bisearch(a[i]);
        add(x[i],-1);
        y[i]=bisearch(b[i]);
        add(y[i],-1);
    }
    for(int i=1;i<=n/2;i++) printf("%d%c",x[i],i==n/2?'\n':' ');
    for(int i=1;i<=n/2;i++) printf("%d%c",y[i],i==n/2?'\n':' ');
    return 0;
}

