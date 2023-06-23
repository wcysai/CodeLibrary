#pragma GCC optimize(3)
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
vector<int> v;
int g(vector<int> &A,vector<int> &B,int x,int d){
    if(!A.size()||!B.size()) return 0;
    if(d==0) return  min((int)A.size(),(int)B.size());
    vector<int> A0,A1,B0,B1;
    for(auto a:A) if(a&(1<<(d-1))) A1.push_back(a); else A0.push_back(a);
    for(auto b:B) if(b&(1<<(d-1))) B1.push_back(b); else B0.push_back(b);
    if(!(x&(1<<(d-1)))){
        if(A0.size()>B1.size()) {swap(A0,B1); swap(A1,B0);}
        if(A1.size()<=B0.size()) return (int)A0.size()+(int)A1.size();
        return (int)A0.size()+(int)B0.size()+min((int)(min(A1.size()-B0.size(),B1.size()-A0.size())),g(A1,B1,x,d-1));
    }
    else{
        return g(A0,B1,x,d-1)+g(A1,B0,x,d-1);
    }
}
int f(vector<int> &A,int x,int d){
    if(!A.size()) return 0;
    if(d==0) return ((int)A.size()/2);
    vector<int> A0,A1;
    for(auto a:A) if(a&(1<<(d-1))) A1.push_back(a); else A0.push_back(a);
    if(!(x&(1<<(d-1)))){
        if(A0.size()>A1.size()) swap(A0,A1);
        return (int)A0.size()+min(((int)A1.size()-(int)A0.size())/2,f(A1,x,d-1));
    }
    else{
        return g(A0,A1,x,d-1);
    }
}
bool check(int x){
    return f(v,x,30)>=(n+1)/2;
}
int main()
{
    scanf("%d",&n);
    int mask=0,ans=0;
    for(int i=1;i<=2*n;i++){
        int x; scanf("%d",&x);
        v.push_back(x);
    }
    int l=0,r=(1<<30);
    while(r-l>1){
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%d\n",l);
    return 0;
}

