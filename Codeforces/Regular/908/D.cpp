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
int t,m,n,k,a[MAXN],cnt[MAXN],s[MAXN],d[MAXN];
int maxi[MAXN],max_cnt[MAXN],used[MAXN];
map<int,int> ans[MAXN];
void clr(){
    for(int i=1;i<=m;i++) ans[i].clear();
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) cnt[i]=used[i]=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cnt[a[i]]++;}
        for(int i=1;i<=m;i++) scanf("%d",&s[i]);
        for(int i=1;i<=m;i++) scanf("%d",&d[i]);
        for(int i=1;i<=m;i++){
            if(d[i]==s[i]) {maxi[i]=1; max_cnt[i]=s[i];}
            else{
                maxi[i]=(s[i]+d[i]-1)/d[i];
                max_cnt[i]=s[i]-(maxi[i]-1)*d[i];
            }
           // printf("%d %d\n",maxi[i],max_cnt[i]);
        }
        set<P> st;
        for(int i=1;i<=n;i++) if(cnt[i]) st.insert(P(cnt[i],i)); 
        bool f=true;
        for(int i=1;i<=m;i++){
            set<int> tmp;
            set<int> has;
            for(int j=0;j<s[i];j++){
                if(!st.size()){
                    f=false; 
                    break;
                }
                int id=(--st.end())->S;
                if(!max_cnt[i]&&used[id]+1==maxi[i]){
                    tmp.insert(id);
                    st.erase(--st.end());
                    j--; continue;
                }
                ans[i][id]++;
                has.insert(id);
                used[id]++; cnt[id]--;
                if(used[id]==maxi[i]){
                    max_cnt[i]--;
                    tmp.insert(id);
                    st.erase(--st.end());
                }
                else{
                    st.erase(--st.end());
                    if(cnt[id]) st.insert(P(cnt[id],id));
                }
            }
            if(!f) break;
            for(auto x:tmp) if(cnt[x]) st.insert(P(cnt[x],x));
            for(auto x:has) used[x]=0;
        }
        if(!f){
            clr();
            printf("-1\n");
            continue;
        }
        else{
            for(int i=1;i<=m;i++){
                vector<P> v;
                for(auto p:ans[i]) v.push_back(P(p.S,p.F));
                sort(v.begin(),v.end());
                vector<int> tmp(s[i]);
                int now=0;
                for(int j=d[i]-1;j>=0;j--){
                    for(int k=j;k<s[i];k+=d[i]){
                        while(!v[now].F) now++;
                        v[now].F--;
                        tmp[k]=v[now].S;
                    }
                }
                for(auto x:tmp) printf("%d ",x);
                printf("\n");
            }
            clr();
        }
    }
    return 0;
}

