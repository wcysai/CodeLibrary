#include<bits/stdc++.h>
#define MAXN 400005
#define MAXLOGN 22
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int B=150;
int n,len,k,a[MAXN];
mt19937_64 wcy(time(NULL));
ull seed[26];
string s[2][MAXN];
int dep[2][MAXN],depth[2][MAXN*2-1];
int id[2][MAXN],ord[MAXN];
vector<int> nxt[MAXN];
ull hsh[MAXN],hsh1[MAXN],hsh2[MAXN];
vector<ull> pre[MAXN],suf[MAXN];
int tmp[26];
void compute_hash(int id){
    pre[id].resize(len+2); suf[id].resize(len+2);
    ull res=0;
    for(int i=0;i<len;i++){
        res=(137ULL*res+seed[s[0][id][i]-'a']);
        pre[id][i]=res;
    }
    res=0;
    for(int i=len-1;i>=0;i--){
        res=(137ULL*res+seed[s[0][id][i]-'a']);
        suf[id][i]=res;
    }
    vector<char> v;
    for(int i=0;i<len;i++) v.push_back(s[0][id][i]);
    sort(v.begin(),v.end());
    res=0;
    for(int i=0;i<len;i++){
        res=(137ULL*res+seed[v[i]-'a']);
    }
    hsh[id]=res;
}
bool cmp(int x,int y){
    if(hsh[x]!=hsh[y]) return hsh[x]<hsh[y];
    return s[0][x]<s[0][y];
}
bool cmp2(int x,int y){
    if(hsh[x]!=hsh[y]) return hsh[x]<hsh[y];
    if(hsh1[x]!=hsh1[y]) return hsh1[x]<hsh1[y];
    return hsh2[x]<hsh2[y];
}
int query_lcp(int x,int y){
    for(int i=0;i<len;i++) if(pre[x][i]!=pre[y][i]) return i;
    return len;
}
int query_lcs(int x,int y){
    for(int i=0;i<len;i++) if(suf[x][len-1-i]!=suf[y][len-1-i]) return i;
    return len;
}
bool is_sorted(int i,int l,int r){
    return nxt[i][l]>=r;
}
ll solve_large(vector<int> &v){
    ll ret=0;
    for(int i=0;i<(int)v.size();i++)
        for(int j=i+1;j<(int)v.size();j++){
            int x=v[i],y=v[j];
            int l=query_lcp(x,y),r=len-1-query_lcs(x,y);
            if(is_sorted(x,l,r)||is_sorted(y,l,r)) ret++; 
        }
    return ret;
}
ll s1[26],s2[26],s3[26*26];
ll get_res(vector<int> &v,int l,int r){
    //printf("l=%d r=%d\n",l,r);<F9>
    ll res=0;
    int sz=(int)v.size();
    for(auto x:v){
        int c1=s[0][x][l]-'a',c2=s[0][x][r]-'a';
        int id=c1*26+c2;
        //printf("x=%d c1=%d c2=%d\n",x,c1,c2);
        s1[c1]++; s2[c2]++; s3[id]++;
    }
    for(auto x:v){
        int c1=s[0][x][l]-'a',c2=s[0][x][r]-'a';
        int id=c1*26+c2;
        res+=sz-1; res-=(s1[c1]-1); res-=(s2[c2]-1); res+=(s3[id]-1); 
    }
    for(auto x:v){
        int c1=s[0][x][l]-'a',c2=s[0][x][r]-'a';
        int id=c1*26+c2;
        s1[c1]=s2[c2]=s3[id]=0;
    }
    return res/2;
}
ll solve_small(vector<int> &v,int l,int r){
    int sz=(int)v.size();
    ll res=get_res(v,l,r);
    vector<int> not_sorted;
    for(auto x:v) if(!is_sorted(x,l,r)) not_sorted.push_back(x);
    res-=get_res(not_sorted,l,r);
    return res;
}
int main(){
    for(int i=0;i<26;i++) seed[i]=wcy();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>s[0][i];
    //sort(s[0]+1,s[0]+n+1);
    len=(int)s[0][1].size();
    for(int i=1;i<=n;i++) compute_hash(i);
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<len;j++) printf("%d ",pre[i][j]);
        printf("\n");
        for(int j=0;j<len;j++) printf("%d ",suf[i][j]);
        printf("\n");
    }*/
    for(int i=1;i<=n;i++){
        s[1][i]=s[0][i];
        reverse(s[1][i].begin(),s[1][i].end());
    }
    for(int i=1;i<=n;i++) nxt[i].resize(len+1);
    for(int i=1;i<=n;i++){
        int last=0;
        for(int j=1;j<len;j++){
            if(s[0][i][j]<s[0][i][j-1]){
                for(int k=last;k<j;k++) nxt[i][k]=j-1;
                last=j;
            }
        }
        for(int k=last;k<len;k++) nxt[i][k]=len-1;
    }
   /* for(int i=1;i<=n;i++){
        for(int j=0;j<len;j++) printf("%d ",nxt[i][j]);
        printf("\n");
    }*/
    ll ans=1LL*n*(n-1)/2*1337;
    for(int i=1;i<=n;i++) ord[i]=i;
    sort(ord+1,ord+n+1,cmp);
    vector<int> tmp;
    for(int i=1;i<=n;i++){
        if(i==1||hsh[ord[i-1]]==hsh[ord[i]]) tmp.push_back(ord[i]);
        else{
            int sz=(int)tmp.size();
            ans-=1LL*sz*(sz-1)/2*1337;
            ans+=1LL*sz*(sz-1);
            if(len>=B) ans-=solve_large(tmp);
            tmp.clear();
            tmp.push_back(ord[i]);
        }
    }
    int sz=(int)tmp.size();
    ans-=1LL*sz*(sz-1)/2*1337;
    ans+=1LL*sz*(sz-1);
   // printf("ans=%lld\n",ans);
    if(len>=B) ans-=solve_large(tmp);
    if(len<B){
        for(int i=0;i<len;i++)
            for(int j=i;j<len;j++){
                for(int k=1;k<=n;k++) {hsh1[k]=(i==0?0:pre[k][i-1]); hsh2[k]=suf[k][j+1]; /*printf("%d %d %d %d\n",k,hsh[k],hsh1[k],hsh2[k]);*/}
                sort(ord+1,ord+n+1,cmp2);
                vector<int> tmp;
                for(int k=1;k<=n;k++){
                    if(k==1||(hsh[ord[k-1]]==hsh[ord[k]]&&(i==0||pre[ord[k-1]][i-1]==pre[ord[k]][i-1])&&suf[ord[k-1]][j+1]==suf[ord[k]][j+1])) tmp.push_back(ord[k]);
                    else{
                        int sz=(int)tmp.size();
                        ans-=solve_small(tmp,i,j);
                       // printf("i=%d j=%d sz=%d ans=%d\n",i,j,(int)tmp.size(),ans);
                       // for(auto x:tmp) printf("%d ",x);
                      //  printf("\n");
                        tmp.clear();
                        tmp.push_back(ord[k]);
                    }
                }
               // printf("i=%d j=%d sz=%d ans=%d\n",i,j,(int)tmp.size(),ans);
                ans-=solve_small(tmp,i,j);
            }
    }
    printf("%lld\n",ans);
    return 0;
}

