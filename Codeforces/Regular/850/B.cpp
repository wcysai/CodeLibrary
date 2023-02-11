#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,char> P;
int t,m,k,a[MAXN];
string str[MAXN];
vector<int> pos[6];//(w,i) (w,n) (i,w) (i,n) (n,w) (n,i)
int cnt[MAXN][3];
vector<pair<P,P> > ans; 
int main()
{
    scanf("%d",&t);
    while(t--){
        ans.clear();
        scanf("%d",&m);
        for(int i=1;i<=m;i++) 
            for(int j=0;j<3;j++)
                cnt[i][j]=0;
        for(int i=0;i<6;i++) pos[i].clear();
        for(int i=1;i<=m;i++) 
        {
            cin>>str[i];
            for(int j=0;j<3;j++){
                if(str[i][j]=='w') cnt[i][0]++;
                else if(str[i][j]=='i') cnt[i][1]++;
                else cnt[i][2]++;
            }
            if(cnt[i][0]>1&&!cnt[i][1]) {pos[0].push_back(i); cnt[i][0]--; cnt[i][1]++;}
            if(cnt[i][0]>1&&!cnt[i][2]) {pos[1].push_back(i); cnt[i][0]--; cnt[i][2]++;}
            if(cnt[i][1]>1&&!cnt[i][0]) {pos[2].push_back(i); cnt[i][1]--; cnt[i][0]++;}
            if(cnt[i][1]>1&&!cnt[i][2]) {pos[3].push_back(i); cnt[i][1]--; cnt[i][2]++;}
            if(cnt[i][2]>1&&!cnt[i][0]) {pos[4].push_back(i); cnt[i][2]--; cnt[i][0]++;}
            if(cnt[i][2]>1&&!cnt[i][1]) {pos[5].push_back(i); cnt[i][2]--; cnt[i][1]++;}
        }
        while(pos[0].size()&&pos[2].size()) {
            int x=pos[0].back(); pos[0].pop_back(); int y=pos[2].back(); pos[2].pop_back();
            ans.push_back(make_pair(P(x,'w'),P(y,'i'))); 
        }
        while(pos[1].size()&&pos[4].size()) {
            int x=pos[1].back(); pos[1].pop_back(); int y=pos[4].back(); pos[4].pop_back();
            ans.push_back(make_pair(P(x,'w'),P(y,'n'))); 
        }
        while(pos[3].size()&&pos[5].size()) {
            int x=pos[3].back(); pos[3].pop_back(); int y=pos[5].back(); pos[5].pop_back();
            ans.push_back(make_pair(P(x,'i'),P(y,'n'))); 
        }
        while(pos[0].size()&&pos[3].size()&&pos[4].size()){
            int x=pos[0].back(); pos[0].pop_back();
            int y=pos[3].back(); pos[3].pop_back();
            int z=pos[4].back(); pos[4].pop_back();
            ans.push_back(make_pair(P(x,'w'),P(y,'i'))); 
            ans.push_back(make_pair(P(y,'w'),P(z,'n'))); 
        }
        while(pos[1].size()&&pos[2].size()&&pos[5].size()){
            int x=pos[1].back(); pos[1].pop_back();
            int y=pos[2].back(); pos[2].pop_back();
            int z=pos[5].back(); pos[5].pop_back();
            ans.push_back(make_pair(P(x,'w'),P(z,'n'))); 
            ans.push_back(make_pair(P(z,'w'),P(y,'i'))); 
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %c %d %c\n",p.F.F,p.F.S,p.S.F,p.S.S);
    }
    return 0;
}

