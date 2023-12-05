#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXLOGN 21
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,k,len,a[MAXN];
int bit[MAXN],depth[MAXN];
string str;
vector<P> times;
vector<pair<int&,int> > upd;
vector<P> upd_bit;
int at[MAXN];
void modify(int &a,int b){
    upd.push_back({a,a});
    a=b;
}
void add(int i,int x){
    while(i<=1000001){
        bit[i]+=x;
        i+=i&-i;
    }
}
void rollback(P p){
    int t1=p.F,t2=p.S;
    while(upd.size()>t1){
        upd.back().F=upd.back().S;
        upd.pop_back();
    }
    while(upd_bit.size()>t2){
        add(upd_bit.back().F,-upd_bit.back().S);
        upd_bit.pop_back();
    }
}
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void apply_add(int i,int x){
    upd_bit.push_back(P(i,x));
    add(i,x);
}
int main(){
    for(int i=1;i<=1000000;i++) depth[i]=1000001;
    add(1000001,1000000);
    scanf("%d",&q);
    while(q--){
        cin>>str;
        if(str=="?"){
            printf("%d\n",sum(len));
        }
        else if(str=="!"){
            rollback(times.back()); times.pop_back();
        }
        else if(str=="+"){
            times.push_back(make_pair((int)upd.size(),(int)upd_bit.size()));
            int x;
            scanf("%d",&x);
            modify(len,len+1);
            if(at[len]){
                int v=at[len];
                apply_add(depth[v],-1);
                modify(depth[v],1000001);
                apply_add(depth[v],1);
                modify(at[len],0);
            }
            if(len<depth[x]){
                if(depth[x]!=1000001){
                    modify(at[depth[x]],0);
                }
                apply_add(depth[x],-1);
                modify(depth[x],len);
                apply_add(len,1);
            }
            if(depth[x]==len){
                modify(at[len],x);
            }
        }
        else{
            times.push_back(make_pair((int)upd.size(),(int)upd_bit.size()));
            int k;
            scanf("%d",&k);
            modify(len,len-k);
        }
    }
    return 0;
}
