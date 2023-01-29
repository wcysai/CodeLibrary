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
int n,k,a[MAXN],b[MAXN];
void check(){
    bool f=true;
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]) f=false;
    }
    if(f) {puts("Yes"); exit(0);}
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    check();
    bool fa=true,fb=true;
    for(int i=1;i<=n-2;i++){
        if(((a[i]&1)+(a[i+1]&1)+(a[i+2]&1))==2) fa=false;
    }
    for(int i=1;i<=n-2;i++){
        if(((b[i]&1)+(b[i+1]&1)+(b[i+2]&1))==2) fb=false;
    }
    if((!fa)&&(!fb)){
        vector<int> v1,v2;
        for(int i=1;i<=n;i++) if(a[i]%2==0) v1.push_back(a[i]);
        for(int i=1;i<=n;i++) if(b[i]%2==0) v2.push_back(b[i]);
        if(v2.size()==2&&v2.size()==2&&v1[0]!=v2[0]) {puts("No"); return 0;}
        sort(a+1,a+n+1); sort(b+1,b+n+1);
        check(); puts("No"); return 0;
    }
    if(fa&&fb){
        int last=1;
        for(int i=1;i<=n;i++){
            if(a[i]&1){
                if(i-last>=3){
                    vector<int> tmp;
                    for(int j=last;j<i;j++) tmp.push_back(a[j]);
                    sort(tmp.begin(),tmp.end());
                    for(int j=last;j<i;j++) a[j]=tmp[j-last];
                }
                last=i+1;
            }
        }
        if(n+1-last>=3) sort(a+last,a+n+1);
        last=1;
        for(int i=1;i<=n;i++){
            if(b[i]&1){
                if(i-last>=3){
                    vector<int> tmp;
                    for(int j=last;j<i;j++) tmp.push_back(b[j]);
                    sort(tmp.begin(),tmp.end());
                    for(int j=last;j<i;j++) b[j]=tmp[j-last];
                }
                last=i+1;
            }
        }
        if(n+1-last>=3) sort(b+last,b+n+1);
        check(); puts("No"); return 0;
    }
    else puts("No");
    return 0;
}

