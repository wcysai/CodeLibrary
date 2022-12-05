#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=505;
typedef double db;
typedef vector<db> vec;
typedef vector<vec> mat;
bool p[maxn],vis[maxn];
const int M=1000000007;
const db eps=1e-7;
int n,m,a[505],b[505],p2[505],t[505],cc[505][10];
int pr[8]={2,3,5,7,11,13,17,19};
int vt(int x,int mask){
    int ret=1;
    for (int i=0;i<8;i++) if ((mask>>i)&1){
        while (x%pr[i]==0) x/=pr[i],ret*=pr[i];
    }
    return ret;
}
bool eq(db a,db b){
    return fabs(a-b)<eps;
}
bool ls(db a,db b){
    return a<b&&!eq(a,b);
}
vec simplex(mat a){
    int n=(int)a.size()-1;
    int m=(int)a[0].size()-1;
    vec left(n+1),up(m+1);
    iota(up.begin(),up.end(),1);
    iota(left.begin(),left.end(),m+1);
    auto pivot=[&](int x,int y){
        swap(left[x],up[y]);
        db k=a[x][y];
        a[x][y]=1;
        vector<int> vct;
        for (int j=0;j<=m;j++){
            a[x][j]/=k;
            if (!eq(a[x][j],0)) vct.pb(j);
        }
        for (int i=0;i<=n;i++){
            if (eq(a[i][y],0)||i==x) continue;
            db coef=a[i][y];
            a[i][y]=0;
            for (int j:vct) a[i][j]-=coef*a[x][j];
        }
    };
    while (1){
        int x=-1;
        for (int i=1;i<=n;i++) if (ls(a[i][0],0)&&(x==-1||a[i][0]<a[x][0])) x=i;
        if (x==-1) break;
        int y=-1;
        for (int j=1;j<=m;j++) if (ls(a[x][j],0)&&(y==-1||a[x][j]<a[x][y])) y=j;
        assert(y!=-1);
        pivot(x,y);
    }
    while (1){
        int y=-1;
        for (int j=1;j<=m;j++) if (ls(0,a[0][j])&&(y==-1||a[0][j]>a[0][y])) y=j;
        if (y==-1) break;
        int x=-1;
        for (int i=1;i<=n;i++) if (ls(0,a[i][y])&&(x==-1||a[i][0]/a[i][y]<a[x][0]/a[x][y])) x=i;
        assert(x!=-1);
        pivot(x,y);
    }
    vector<db> ans(m+1);
    for (int i=1;i<=n;i++) if (left[i]<=m) ans[left[i]]=a[i][0];
    ans[0]=-a[0][0];
    return ans;
}
bool check(int x){
    for (int i=23;i<=500;i++) if (!p[i]&&x%i==0) return 1;
    int mask=0;
    vector<int> pp(0);
    for (int i=0;i<8;i++) if (x%pr[i]==0) mask|=1<<i,pp.pb(pr[i]);
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;i++) t[i]=vt(b[i],mask),vis[t[i]]=1;
    for (int i=2;i<=500;i++)
        for (int j=2;j*i<=500;j++)
            if (vis[i*j]) vis[i]=1;
    vector<int> B(0);
    for (int i=2;i<=500;i++) if (vis[i]) B.pb(i);
    int nn=pp.size(),mm=B.size();
    for (int i=0;i<nn;i++){
        bool ok=0;
        for (int j=0;j<mm;j++) if (B[j]%pp[i]==0) ok=1;
        if (!ok) return 1;
    }
    for (int i=1;i<=500;i++){
        for (int j=0;j<pp.size();j++){
            cc[i][j]=0;
            int tmp=i;
            while (tmp%pp[j]==0) tmp/=pp[j],cc[i][j]++;
        }
    }
    mat A(nn+1,vec(mm+1)); A[0][0]=0;
    for (int i=1;i<=mm;i++) A[0][i]=-1.0;
    for (int i=0;i<nn;i++){
        A[i+1][0]=-cc[x][i];
        for (int j=0;j<mm;j++) A[i+1][j+1]=-cc[B[j]][i];
    }
    vec ans=simplex(A);
    db res=-ans[0];
    //printf("%.4f\n",res);
    if (res<1.0-eps) return 0;
    return 1;
}
int main(){
    for (int i=2;i<=500;i++)
        for (int j=2;j*i<=500;j++)
            p[i*j]=1;
    p2[0]=1; for (int i=1;i<=500;i++) p2[i]=p2[i-1]*2%M;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    int cnt=0;
    for (int i=1;i<=n;i++) if (!check(a[i])) cnt++;
    printf("%d\n",(p2[n]-p2[cnt]+M)%M);
}