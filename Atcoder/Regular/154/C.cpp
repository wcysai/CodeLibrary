#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN],c[MAXN];
vector<int> v1,v2;
void shift(){
    int x=a[1];
    for(int i=1;i<=n-1;i++) a[i]=a[i+1]; a[n]=x;
}
bool check(){
    int now=0;
    for(int i=0;i<(int)v2.size();i++){
        while(now<(int)v1.size()&&v1[now]!=v2[i]) now++;
        if(now==(int)v1.size()) return false;
        now++;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool rot=false;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); }
        for(int i=1;i<=n;i++) {scanf("%d",&b[i]); }
        for(int i=1;i<=n-1;i++) if(b[i]==b[i+1]) rot=true;
        if(b[n]==b[1]) rot=true;
        if(!rot){
            bool f=true;
            for(int i=1;i<=n;i++) if(a[i]!=b[i]) f=false;
            if(f) puts("Yes"); else puts("No");
            continue;
        }
        v1.clear(); v2.clear();
        for(int i=1;i<=n;i++) if(i==1||a[i]!=a[i-1]) v1.push_back(a[i]);
        if(v1.size()>1&&v1[0]==v1.back()) v1.pop_back();
        for(int i=1;i<=n;i++) if(i==1||b[i]!=b[i-1]) v2.push_back(b[i]);
        if(v2.size()>1&&v2[0]==v2.back()) v2.pop_back();
        bool f=false;
        if(check()) f=true;
        for(int i=0;i<n-1;i++){
            rotate(v1.begin(),v1.begin()+1,v1.end());
            if(check()) f=true;
        }
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}

