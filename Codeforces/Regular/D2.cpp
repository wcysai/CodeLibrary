#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define B 405
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int sum[MAXN];
int fst[2*MAXN],res[MAXN];
vector<int> pos[MAXN];
int nxt[MAXN],pre[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); pos[a[i]].push_back(i);}
    int num=0,id=-1,ans=0;
    for(int i=1;i<=n;i++) if(pos[i].size()>num) {num=pos[i].size(); id=i;}
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]==id?1:0);
    for(int i=1;i<=n;i++) if(a[i]==id) pre[i]=i; else pre[i]=pre[i-1];
    for(int i=n;i>=1;i--) if(a[i]==id) nxt[i]=i; else nxt[i]=nxt[i+1];
    memset(fst,-1,sizeof(fst));
    for(int i=1;i<=n;i++){
        if(i==id) continue;
        if(pos[i].size()>=B){
            fst[n]=0;
            for(int j=1;j<=n;j++){
                if(a[j]==id) res[j]=res[j-1]+1;
                else if(a[j]==i) res[j]=res[j-1]-1;
                else res[j]=res[j-1];
                if(fst[n+res[j]]!=-1) ans=max(ans,j-fst[n+res[j]]);
                else fst[n+res[j]]=j;
            }
            memset(fst,-1,sizeof(fst));
        }
        else{
            if(!pos[i].size()) continue;
            vector<P> tmp;
            int now=0,sz=(int)pos[i].size();
            for(int j=0;j<(int)pos[i].size();j++){
                int x=pos[i][j];
                if(sum[x]-now>sz+1){
                    now=sum[x]-(sz+1);
                }
                for(;now<sum[x]+sz+1&&now<(int)pos[id].size();now++){
                    tmp.push_back(P(pos[id][now],1));
                }
            }
            vector<P> tmp2;
            int id1=0,id2=0;
            while(id1<pos[i].size()||id2<tmp.size()){
                if(id1<pos[i].size()&&(id2==tmp.size()||pos[i][id1]<tmp[id2].F)) {tmp2.push_back(P(pos[i][id1],-1)); id1++;}
                else {tmp2.push_back(tmp[id2]); id2++;}
            }
            swap(tmp,tmp2);
            //for(auto p:tmp) printf("(%d %d) ",p.F,p.S);
            //printf("\n");
            vector<int> changed;
            int sum=0;
            fst[n]=0; 
            for(int k=0;k<(int)tmp.size();k++){
                int pre,suf;
                pre=tmp[k].F;
                if(k==(int)tmp.size()-1) suf=n; else suf=tmp[k+1].F-1;
                sum+=tmp[k].S;
                //printf("k=%d sum=%d pre=%d suf=%d ans=%d\n",k,sum,pre,suf,ans);
                if(fst[n+sum]!=-1) ans=max(ans,suf-fst[n+sum]);
                else {changed.push_back(n+sum); fst[n+sum]=pre;}
            }
            for(auto x:changed) fst[x]=-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}

