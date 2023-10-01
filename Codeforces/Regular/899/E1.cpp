#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN],tmp[MAXN];
void perform(int n,int *a,int pos){
    int t=0;
    for(int i=pos+1;i<=n;i++) tmp[++t]=a[i];
    tmp[++t]=a[pos];
    for(int i=1;i<=pos-1;i++) tmp[++t]=a[i];
    for(int i=1;i<=n;i++) a[i]=tmp[i];
}
vector<int> cons(int n,int *a){
    vector<int> ret;
    for(int i=n;i>=1;i--){
        int pos=-1;
        for(int j=1;j<=n;j++){
            if(a[j]==i){
                pos=j; break;
            }
        }
        if(pos==1) continue;
        else{
            int npos=1+n-pos;
            ret.push_back(pos);
            perform(n,a,pos);
            if(npos!=1) {
                ret.push_back(npos-1);
                perform(n,a,npos-1);
            }
        }
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    vector<int> aa=cons(n,a),bb=cons(m,b);
    if(n%2==0&&m%2==0&&((aa.size()+bb.size())&1)){
        puts("-1"); return 0;
    }
    while(aa.size()+2<=bb.size()) {aa.push_back(1); aa.push_back(n);}
    while(bb.size()+2<=aa.size()) {bb.push_back(1); bb.push_back(m);}
    if(aa.size()!=bb.size()){
        if(n&1){
            for(int i=0;i<n;i++) aa.push_back(1);
            while(bb.size()+2<=aa.size()) {bb.push_back(1); bb.push_back(m);}
        }
        else{
            for(int i=0;i<m;i++) bb.push_back(1);
            while(aa.size()+2<=bb.size()) {aa.push_back(1); aa.push_back(n);}
        }
    }
    assert(aa.size()==bb.size());
    printf("%d\n",(int)aa.size());
    for(int i=0;i<(int)aa.size();i++) printf("%d %d\n",aa[i],bb[i]);
    return 0;
}

