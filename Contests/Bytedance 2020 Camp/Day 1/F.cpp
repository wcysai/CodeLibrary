#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define rep(i,n) for(ll i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck0
#define y0 fuck1
#define x1 fuck2
#define y1 fuck3
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
map<ll,int>dic;
ll rev[30000];
int to[30000][35];
int n,k,col[1005],C[35][35],tot;
bool in[30000];
ld ans[30000];
int tmp[35],tmp2[35];
ld sol(int c);
int rgvec(vector<int>&a,ll x);
//map<pair<int,pair<int,int>>>
int ty(const vector<int>&a,int len,int now,int cursta,int pi,int res,int ini,int presum){
    if(now==len+1){
        if(cursta==ini)return pi;
        //sol(cursta);
        return 0;
    }
    int cnt=0;
    for(int i=0;i<=a[now]&&i<=res;i+=a[now]){
        if(res-i>n-presum-a[now])continue;
        cnt+=ty(a,len,now+1,to[to[cursta][i]][a[now]-i],pi*C[a[now]][i],res-i,ini,presum+a[now]);
    }
    return cnt;
}

ld dwn(const vector<int>&a,int len,int now,int cursta,int pi,int res,int ini,int presum,int lop,map<pair<int,pair<int,int>>,ld>&tmpdic){
    auto key=mp(now,mp(cursta,res));
    if(tmpdic.find(key)!=tmpdic.end())return pi*tmpdic[key];
    if(now==len+1){
        if(cursta==ini)return 0;
        return 1.L*pi/(C[n][k]-lop)*sol(cursta);
    }
    ld ret=0;
    for(int i=max(0,res-(n-presum-a[now]));i<=a[now]&&i<=res;++i){
        //if(res-i>)continue;
        ret+=dwn(a,len,now+1,to[to[cursta][i]][a[now]-i],pi*C[a[now]][i],res-i,ini,presum+a[now],lop,tmpdic);
    }
    tmpdic[key]=ret/pi;
    return ret;
}

ld sol(int c){
    if(in[c])return ans[c];
    in[c]=1;
    vector<int>a;
    int len=rgvec(a,rev[c]);
    int lop=ty(a,len,1,dic[0],1,k,c,0);
    //printf("%d %lld %d\n",c,rev[c],lop);
    map<pair<int,pair<int,int>>,ld>tmpdic;
    tmpdic.clear();
    return ans[c]=1/(1-1.l*lop/C[n][k])+dwn(a,len,1,dic[0],1,k,c,0,lop,tmpdic);
}

ll gt(int a[],int n){
    if(n>1)sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ll x=0,sum=0;
    rep(i,n){
        sum+=a[i];
        x|=1ll<<(sum-1);
    }
    return x;
}
int rg(int a[],ll x){
    int now=0;
    while(x){
        int cnt=0;
        while(x%2==0)x/=2,++cnt;
        a[++now]=cnt+1,x/=2;
    }
    return now;
}
int rgvec(vector<int>&a,ll x){
    a.clear();a.pb(0);
    int now=0;
    while(x){
        int cnt=0;
        while(x%2==0)x/=2,++cnt;
        ++now,a.pb(cnt+1),x/=2;
    }
    return now;
}
void dfs(int res,int now){
    if(res==0){
        rep(i,now-1)tmp2[i]=tmp[i];
        ll x=gt(tmp2,now-1);
        if(dic.find(x)==dic.end()){
            dic[x]=++tot;
            rev[tot]=x;
        }
        return;
    }
    for(int i=1;i<=tmp[now-1]&&i<=res;++i){
        tmp[now]=i;
        dfs(res-i,now+1);
    }
}
int main(){
    C[0][0]=1;
    rep(i,30){
        C[i][0]=1;
        rep(j,i)C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    tot=0;tmp[0]=1e9+7;
    for(int i=0;i<=30;++i)
        dfs(i,1);
    
    for(auto p:dic){
        int siz=rg(tmp,p.st);
        int sum=0;
        rep(i,siz)sum+=tmp[i];
        rep(i,30-sum){
            //if(p.nd%100==0)printf("%d %lld\n",p.nd,i);
            rep(i,siz)tmp2[i]=tmp[i];
            tmp2[siz+1]=i;
            to[p.nd][i]=dic[gt(tmp2,siz+1)];
        }
        to[p.nd][0]=p.nd;
    }
    
    //printf("%d\n",tot);
    scanf("%d%d",&n,&k);
    //n=24,k=10;
    rep(i,n){
        //int x=1;
        int x;scanf("%d",&x);
        ++col[x];
    }
    sort(col+1,col+1005);
    reverse(col+1,col+1005);
    ll now=0,cnt=0;
    rep(i,1004)if(col[i]==0){cnt=i-1;break;}
    //rep(i,cnt)printf("%d\n",col[i]);
    now=gt(col,cnt);
    //printf("%lld\n",now);
    int u=dic[(1ll<<n)-1];
    in[u]=1;ans[u]=0;
    printf("%.15Lf\n",sol(dic[now]));
    return 0;
}