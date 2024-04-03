#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,k,a[MAXN];
struct ch{
    int type,t;
    P st[MAXN];
    void add(int u,int v){
        P p=P(u,v);
        if(type==1){
            while((t>0&&(st[t-1].F==p.F)||(t>1&&1LL*(st[t-1].F-st[t-2].F)*(p.S-st[t-1].S)>=1LL*(st[t-1].F-p.F)*(st[t-2].S-st[t-1].S)))) t--;
        }
        else{
            while((t>0&&(st[t-1].F==p.F)||(t>1&&1LL*(st[t-1].F-st[t-2].F)*(p.S-st[t-1].S)>=1LL*(st[t-1].F-p.F)*(st[t-2].S-st[t-1].S)))) t--;
        }
        st[t++]=p;
    }
    db query(db x){
        ll l=-1,r=t-1;
        while(r-l>1){
            ll mid=(l+r)/2;
            if(type==0){
                if(st[mid].F*x+st[mid].S>=st[mid+1].F*x+st[mid+1].S) l=mid;
                else r=mid;
            }
            else{
                if(st[mid].F*x+st[mid].S<=st[mid+1].F*x+st[mid+1].S) l=mid;
                else r=mid;
            }
        }
        return st[r].F*x+st[r].S;
    }
}xup,xdown,yup,ydown;
db calc(db t){
   // printf("t=%.10f\n",t);
    //printf("%.10f %.10f %.10f %.10f\n",yup.query(t),ydown.query(t),xup.query(t),xdown.query(t));
    db res=(yup.query(t)-ydown.query(t))*(xup.query(t)-xdown.query(t));
    //printf("res=%.10f\n",res);
    return res;
}
int main(){
    scanf("%d",&n);
    vector<P> vecx,vecy;
    for(int i=0;i<n;i++){
        int x,y,vx,vy;
        scanf("%d%d%d%d",&x,&y,&vx,&vy);
        vecx.push_back(P(vx,x)); vecy.push_back(P(vy,y));
    }
    sort(vecx.begin(),vecx.end()); sort(vecy.begin(),vecy.end());
    xup.type=yup.type=1; xdown.type=ydown.type=0;
    for(auto p:vecx) xup.add(p.F,p.S);
    for(auto p:vecy) yup.add(p.F,p.S);
    reverse(vecx.begin(),vecx.end()); reverse(vecy.begin(),vecy.end());
    for(auto p:vecx) xdown.add(p.F,p.S);
    for(auto p:vecy) ydown.add(p.F,p.S);
    /*for(int i=0;i<xup.t;i++) printf("%d %d\n",xup.st[i].F,xup.st[i].S);
    printf("---------\n");
    for(int i=0;i<yup.t;i++) printf("%d %d\n",xdown.st[i].F,xdown.st[i].S);
    printf("---------\n");
    for(int i=0;i<xdown.t;i++) printf("%d %d\n",yup.st[i].F,yup.st[i].S);
    printf("---------\n");
    for(int i=0;i<ydown.t;i++) printf("%d %d\n",ydown.st[i].F,ydown.st[i].S);
    printf("---------\n");*/
    db ans=calc(0.0);
    for(int i=0;i<xup.t-1;i++){
        db t=1.0*(xup.st[i+1].S-xup.st[i].S)/(xup.st[i].F-xup.st[i+1].F);
        if(t>=0) ans=min(ans,calc(t));
    }
    for(int i=0;i<xdown.t-1;i++){
        db t=1.0*(xdown.st[i+1].S-xdown.st[i].S)/(xdown.st[i].F-xdown.st[i+1].F);
        if(t>=0) ans=min(ans,calc(t));
    }
    for(int i=0;i<yup.t-1;i++){
        db t=1.0*(yup.st[i+1].S-yup.st[i].S)/(yup.st[i].F-yup.st[i+1].F);
        if(t>=0) ans=min(ans,calc(t));
    }
    for(int i=0;i<ydown.t-1;i++){
        db t=1.0*(ydown.st[i+1].S-ydown.st[i].S)/(ydown.st[i].F-ydown.st[i+1].F);
        if(t>=0) ans=min(ans,calc(t));
    }
    printf("%.15Lf\n",ans);
    return 0;
}

