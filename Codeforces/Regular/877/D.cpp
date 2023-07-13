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
int n,q,a[MAXN];
char str[MAXN];
int pre[MAXN],suf[MAXN];
set<int> s1,s2;
struct segtree{
    int lazy[4*MAXN],mini[4*MAXN];
    void pushup(int k){
        mini[k]=min(mini[k*2],mini[k*2+1]);
    }
    void add(int k,int v){
        lazy[k]+=v; mini[k]+=v;
    }
    void pushdown(int k){
        if(!lazy[k]) return;
        for(int i=k*2;i<=k*2+1;i++) add(i,lazy[k]);
        lazy[k]=0;
    }
    void build(int k,int l,int r){
        if(l==r){
            mini[k]=pre[l];
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,int v){
        if(l>y||x>r) return;
        if(l>=x&&r<=y){
            add(k,v);
            return;
        }
        pushdown(k);
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y){
        if(l>y||x>r) return INF;
        if(l>=x&&r<=y) return mini[k];
        pushdown(k);
        int mid=(l+r)/2;
        return min(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg1,seg2;
void flip(int pos){
    if(str[pos]=='('){
        if(pos>1&&str[pos-1]=='(') s1.erase(pos-1);
        if(pos<n&&str[pos+1]=='(') s1.erase(pos);
        if(pos>1&&str[pos-1]==')') s2.insert(pos-1);
        if(pos<n&&str[pos+1]==')') s2.insert(pos);
        seg1.update(1,1,n,pos,n,-2); seg2.update(1,1,n,1,pos,2);
    }
    else{
        if(pos>1&&str[pos-1]=='(') s1.insert(pos-1);
        if(pos<n&&str[pos+1]=='(') s1.insert(pos);
        if(pos>1&&str[pos-1]==')') s2.erase(pos-1);
        if(pos<n&&str[pos+1]==')') s2.erase(pos);
        seg1.update(1,1,n,pos,n,2); seg2.update(1,1,n,1,pos,-2);
    }
    str[pos]='('+')'-str[pos];
}
bool check(){
    if(!s1.size()||!s2.size()) return seg1.query(1,1,n,1,n)==0&&seg1.query(1,1,n,n,n)==0;
    int x=*s1.begin(); int y=*(--s2.end());
    //printf("x=%d y=%d\n",x,y);
    if(x>y){
        return false;
    }
    //printf("res1=%d res2=%d\n",seg1.query(1,1,n,1,x),seg2.query(1,1,n,y,n));
    return seg1.query(1,1,n,1,x)>=0&&seg2.query(1,1,n,y,n)>=0;
}
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",str+1);
    if(n&1){
        for(int i=1;i<=q;i++){
            int x; scanf("%d",&x);
            puts("NO");
        }
    }
    else{
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(str[i]=='('?1:-1);
        seg1.build(1,1,n);
        for(int i=n;i>=1;i--) pre[i]=pre[i+1]+(str[i]=='('?-1:1);
        seg2.build(1,1,n);
        for(int i=1;i<=n-1;i++) {
            if(str[i]=='('&&str[i+1]=='(') s1.insert(i);
            if(str[i]==')'&&str[i+1]==')') s2.insert(i);
        }
        for(int i=1;i<=q;i++){
            int x; scanf("%d",&x);
            flip(x);
            if(check()) puts("YES"); else puts("NO");
        }
    }
    return 0;
}

