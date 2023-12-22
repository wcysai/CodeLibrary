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
int t,n,k,a[MAXN];
vector<P> ans;
vector<int> pos,neg;
void solve_pos(){
    for(int i=2;i<=n;i++){
        a[i]+=a[i-1];
        ans.push_back(P(i,i-1));
    }
}
void solve_neg(){
    for(int i=n-1;i>=1;i--){
        a[i]+=a[i+1];
        ans.push_back(P(i,i+1));
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        pos.clear(); neg.clear(); ans.clear();
        P maxpos=P(-INF,0),maxneg=P(-INF,0);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]); if(a[i]>0) {pos.push_back(i); maxpos=max(maxpos,P(a[i],i));} 
            else {neg.push_back(i); maxneg=max(maxneg,P(-a[i],i));}
        }
        if(!neg.size()) solve_pos();
        else if(!pos.size()) solve_neg();
        else{ 
            int posneed=(int)neg.size(),negneed=(int)pos.size();
            int x=maxpos.F,y=maxneg.F;
            while(x<y) {x*=2; posneed++;}
            x=maxpos.F; y=maxneg.F;
            while(y<x) {y*=2; negneed++;}
            if(posneed<=12) {
                while(maxpos.F<maxneg.F) {a[maxpos.S]*=2; maxpos.F*=2; ans.push_back(P(maxpos.S,maxpos.S));}
                for(auto x:neg) {a[x]+=maxpos.F; ans.push_back(P(x,maxpos.S));}
                solve_pos();
            }
            else{
                while(maxneg.F<maxpos.F) {a[maxneg.S]*=2; maxneg.F*=2; ans.push_back(P(maxneg.S,maxneg.S));}
                for(auto x:pos) {a[x]-=maxneg.F; ans.push_back(P(x,maxneg.S));}
                solve_neg();
            }
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

