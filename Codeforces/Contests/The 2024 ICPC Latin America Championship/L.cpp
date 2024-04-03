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
int r,c,k,a[MAXN];
string s[MAXN],t[MAXN];
int main(){
    scanf("%d%d%d",&r,&c,&k);
    for(int i=0;i<r;i++){
        cin>>s[i]>>t[i];
    }
    bool f=true;
    for(int i=0;i<r;i++){
        bool flag=false;
        for(int j=0;j<k;j++) if(t[i][j]=='*') flag=true;
        if(flag){
            flag=true;
            for(int j=0;j<c;j++) if(s[i][j]=='-') flag=false;
            if(!flag) f=false;
        }
    }
    if(f) puts("Y"); else puts("N");
    return 0;
}

