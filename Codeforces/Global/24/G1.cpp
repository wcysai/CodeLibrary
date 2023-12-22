#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int qry(int l,int r,int k){
    printf("? %d %d %d\n",l,r,k);
    fflush(stdout);
    int x; scanf("%d",&x);
    return x;
}
int ask(int l,int r){
    return r-l+1-qry(l,r,2);
}
void answer(int pos){
    printf("! %d\n",pos);
    fflush(stdout);
}
void solve_odd(){
    int l=0,r=n;
    while(r-l>1){
        int mid=(l+r)/2;
        int x=mid-2*ask(1,mid),y=n-mid-2*ask(mid+1,n);
        if(x>y) r=mid; else l=mid;
    }
    answer(r);
}
void solve_even(){
    int l=0,r=n;
    while(r-l>1){
        int mid=(l+r)/2;
        int x=mid-2*ask(1,mid),y=n-mid-2*ask(mid+1,n);
        if(x>y) r=mid; else if(x<y) l=mid;
        else{
            if(mid==1){
                if(qry(mid+1,n,n)!=2) l=mid; else r=mid;
            }
            else if(qry(1,mid,n)!=2) r=mid; else l=mid;
        }
    }
    answer(r);
}
int main(){
    scanf("%d",&n);
    if(n&1) solve_odd(); else solve_even();
    return 0;
}

