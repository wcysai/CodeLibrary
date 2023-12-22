#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int t,n;
char str[MAXN];
vector<int> ans;
void solve(int l,int r,int pre){
    if(l>r) return;
    if(str[l]!=str[r]) {solve(l+1,r-1,pre+1); return;}
    if(str[l]=='0'){
        ans.push_back(pre+r-l+1);
        str[r+1]='0';
        solve(l+1,r+1,pre+1); return;
    }
    else{
        ans.push_back(pre);
        str[l-1]='1';
        solve(l-1,r-1,pre+1); return;
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",str+1);
        for(int i=n+1;i<=2*n;i++) str[i]=str[i-n];
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++) if(str[i]=='0') cnt0++; else cnt1++;
        if(cnt0!=cnt1) {puts("-1"); continue;}
        ans.clear();
        solve(n+1,2*n,0);
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d ",p);
        printf("\n");
    }
}
