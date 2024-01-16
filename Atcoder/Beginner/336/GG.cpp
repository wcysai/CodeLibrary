#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
typedef vector<int> vec;
typedef vector<vec> mat;
int cnt[MAXN];
int fa[MAXN];
void init(){
    for(int i=0;i<8;i++) fa[i]=i;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x); y=find(y);
    fa[x]=y;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int det_mod(mat A,int M){
	int n=(int)A.size();
	int ans=1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			while(A[j][i]!=0){
				int t=A[i][i]/A[j][i];
				for(int k=0;k<n;k++){
					dec(A[i][k],1LL*A[j][k]*t%MOD);
					swap(A[i][k],A[j][k]);
				}
				ans=(MOD-ans)%MOD;
			}
			if(A[i][i]==0) return 0;
		}
		ans=1LL*ans*A[i][i]%MOD;
	}
	return ans;
}
int fact[MAXN],invf[MAXN],ideg[MAXN],odeg[MAXN];
int a[10][10];
int id[8];
int get_ans(){
    int res=1;
    //for(int i=0;i<8;i++) if(odeg[i]==0) return 0;
    for(int i=0;i<8;i++) assert(ideg[i]==odeg[i]);
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            res=1LL*res*invf[a[i][j]]%MOD;
    int tot=-1;
    vector<int> valid;
    memset(id,-1,sizeof(id));
    for(int i=0;i<8;i++) if(odeg[i]) res=1LL*res*fact[odeg[i]-1]%MOD;
    int tmp=-1;
    for(int i=0;i<8;i++) {
        if(ideg[i]) {if(tot==-1) {tot=0;tmp=find(i);} else {if(find(i)!=tmp) return 0; valid.push_back(i); id[i]=tot++;}}
    }
    if(!valid.size()) return 1;
    int sz=(int)valid.size();
    mat A(sz,vec(sz));
    for(int i=0;i<8;i++){
        if(id[i]==-1) continue;
        for(int j=0;j<8;j++){
            if(id[j]==-1) continue;
            int x=id[i],y=id[j];
            if(x==y) A[x][y]=ideg[i]-a[i][i]; else A[x][y]=(MOD-a[i][j])%MOD;
        }
    }
    res=1LL*res*det_mod(A,MOD)%MOD;
    return res;
}
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=1000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[1000000]=pow_mod(fact[1000000],MOD-2);
    for(int i=999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=0;i<16;i++) scanf("%d",&cnt[i]);
    init();
    for(int i=0;i<16;i++){
        int x=(i>>1),y=i&7;
        a[x][y]=cnt[i];
        unite(x,y);
        ideg[y]+=cnt[i]; odeg[x]+=cnt[i];
    }
    vector<int> v;
    for(int i=0;i<8;i++) if(ideg[i]!=odeg[i]) v.push_back(i);
    if(v.size()!=0&&v.size()!=2){
        puts("0"); return 0;
    }
    else if(v.size()==2){
       // puts("here");
        int x=v[0];
        if(ideg[x]-odeg[x]==1){
            a[v[0]][v[1]]++; ideg[v[1]]++; odeg[v[0]]++; unite(v[0],v[1]);
            printf("%d\n",get_ans());
        }
        else if(ideg[x]-odeg[x]==-1){
            a[v[1]][v[0]]++; ideg[v[0]]++; odeg[v[1]]++; unite(v[0],v[1]);
            printf("%d\n",get_ans());
        }
        else {
            puts("0");
            return 0;
        }
    }
    else{
        int ans=0;
        for(int i=0;i<8;i++) {
            if(!ideg[i]) continue;
            a[i][i]++; ideg[i]++; odeg[i]++;
            add(ans,get_ans());
            a[i][i]--; ideg[i]--; odeg[i]--;
        }
        printf("%d\n",ans);
    }
    return 0;
}

