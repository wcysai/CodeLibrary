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
map<P,int> mp;
int qry(int l,int r,int k){
    if(l==1&&r==n) return n/k+1;
    if(l>r) return 0;
    if(k==2){
        if(mp.find(P(l,r))!=mp.end()) return mp[P(l,r)];
    }
    printf("? %d %d %d\n",l,r,k);
    fflush(stdout);
    int x; scanf("%d",&x);
    if(k==2) mp[P(l,r)]=x;
    return x;

}
int ask(int l,int r){
    return r-l+1-qry(l,r,2);
}
void answer(int pos){
    printf("! %d\n",pos);
    fflush(stdout);
    exit(0);
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
    int flag=-1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(l+2==r){
            int x=ask(1,l),y=ask(1,r);
            if(x+1==y){
                if(ask(1,l+1)==x) answer(l+1); else answer(r);
            }
            x=ask(l+1,n); y=ask(r+1,n);
            if(x==y+1){
                if(ask(r,n)==y) answer(r); else answer(l+1);
            }
            if(l>=1){
                if(qry(1,l+1,n)==2) answer(r);
                else answer(l+1);
            }
            else{
                if(qry(r,n,n)==2) answer(l+1);
                else answer(r);
            }
        }
        int x=mid-2*ask(1,mid),y=n-mid-2*ask(mid+1,n);
        if(x>y) r=mid; else if(x<y) l=mid;
        else{
            if(flag==1) l=mid; else if(flag==0) r=mid;
            else if(mid==1){
                if(qry(mid+1,n,n)!=2) {l=mid; flag=1;} else {r=mid; flag=0;}
            }
            else if(qry(1,mid,n)!=2) {r=mid; flag=0;} else {l=mid; flag=1;}
        }
    }
    answer(r);
}
int main(){
    scanf("%d",&n);
    if(n&1) solve_odd(); else solve_even();
    return 0;
}

