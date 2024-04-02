#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN];
vector<string> mp;
string str;
int cnt[3];
void add(int x,int y){
    if(mp[x][y]=='.') cnt[0]++;
    else if(mp[x][y]=='x') cnt[1]++;
}
void del(int x,int y){
    if(mp[x][y]=='.') cnt[0]--;
    else if(mp[x][y]=='x') cnt[1]--;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        cin>>str;
        mp.push_back(str);
    }
    int ans=INF;
    if(k<=m){
    for(int i=0;i<n;i++){
        cnt[0]=cnt[1]=0;
        for(int j=0;j<k;j++) add(i,j);
        if(!cnt[1]) ans=min(ans,cnt[0]);
        for(int j=k;j<m;j++){
            add(i,j); del(i,j-k);
            if(!cnt[1]) ans=min(ans,cnt[0]);
        }
    }
    }
    if(k<=n){
    for(int j=0;j<m;j++){
        cnt[0]=cnt[1]=0;
        for(int i=0;i<k;i++) add(i,j);
        if(!cnt[1]) ans=min(ans,cnt[0]);
        for(int i=k;i<n;i++){
            add(i,j); del(i-k,j);
            if(!cnt[1]) ans=min(ans,cnt[0]);
        }
    }
    }
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}

