#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,k,a[MAXN],b[MAXN],u[MAXN],w[MAXN];
vector<int> va,vb;
bool cmpa(int x,int y){
    return 1LL*(b[x]-a[x])*a[y]<1LL*(b[y]-a[y])*a[x];
}
bool cmpb(int x,int y){
    return 1LL*(a[x]-b[x])*b[y]<1LL*(a[y]-b[y])*b[x];
}
int main(){
    scanf("%d",&n);
    db sa=0,sb=0;
    db cura=0,curb=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i],&u[i],&b[i],&w[i]);
        sa+=a[i]*u[i]; sb+=b[i]*w[i];
        if(a[i]>b[i]){
            vb.push_back(i);
            curb+=b[i]*(u[i]+w[i]);
        }
        else{
            va.push_back(i);
            cura+=a[i]*(u[i]+w[i]);
        }
    }
    db sum=cura+curb;
    //printf("%.15Lf\n",sum);
    if(cura>sa){
        sort(va.begin(),va.end(),cmpa);
        for(int i=0;i<(int)va.size();i++){
            int id=va[i];
            db res=min(cura-sa,(db)1.0*a[id]*(u[id]+w[id]));
            cura-=res;
            sum+=res/a[id]*(b[id]-a[id]);
        }
    }
    else if(curb>sb){
        sort(vb.begin(),vb.end(),cmpb);
        for(int i=0;i<(int)vb.size();i++){
            int id=vb[i];
            db res=min(curb-sb,(db)1.0*b[id]*(u[id]+w[id]));
            curb-=res;
            sum+=res/b[id]*(a[id]-b[id]);
        }
    }
    printf("%.15Lf\n",sum);
    return 0;
}

