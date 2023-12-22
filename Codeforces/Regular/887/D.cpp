#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char str[MAXN],ans[MAXN];
vector<P> dp[MAXN][2];
void reduce(vector<P> &v){
    sort(v.begin(),v.end());
    vector<P> tmp;
    for(auto p:v){
        if(!tmp.size()||tmp.back().S+1<p.F) tmp.push_back(p);
        else{
            int f=tmp.back().F,s=tmp.back().S;
            tmp.pop_back();
            tmp.push_back(P(f,max(s,p.S)));
        }
    }
    swap(v,tmp);
}
bool check(int x,int y,int k){
    for(auto p:dp[x][y]) if(k>=p.F&&k<=p.S) return true;
    return false;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s",str+1);
        for(int i=1;i<=n-1;i++) if(str[i]!=str[i+1]) k--;
        if(k<0) {puts("NO"); continue;}
        for(int i=1;i<=n;i++) {dp[i][0].clear(); dp[i][1].clear();}
        if(str[1]=='A'){
            dp[1][0].push_back(P(0,0)); dp[1][1].push_back(P(1,1));
        }
        else{
            dp[1][0].push_back(P(1,1)); dp[1][1].push_back(P(0,0));
        }
        for(int i=2;i<=n;i++){
            vector<P> t1,t2;
            int x=(str[i]=='B'?1:0);
            for(auto p:dp[i-1][0]){
                t1.push_back(P(p.F+x,p.S+x));
                t2.push_back(P(p.F+2-x,p.S+2-x));
            }
            for(auto p:dp[i-1][1]){
                t1.push_back(P(p.F+1+x,p.S+1+x));
                t2.push_back(P(p.F+1-x,p.S+1-x));
            }
            reduce(t1); reduce(t2);
            swap(dp[i][0],t1); swap(dp[i][1],t2);
        }
        int last=0;
        if(check(n,1,k)) last=1;
        else if(!check(n,0,k)) {puts("NO"); continue;}
        puts("YES");
        ans[n]='A'+last;
        if(last+'A'!=str[n]) k--;
        for(int i=n-1;i>=1;i--){
            if(check(i,0,k-last)){
                k-=last;
                last=0;
            }
            else{
                k-=(1-last);
                last=1;
            }
            ans[i]='A'+last;
            if(last+'A'!=str[i]) k--;
        }
        for(int i=1;i<=n;i++) printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}

