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
int t,n,k,a[MAXN],u[MAXN],l[MAXN],d[MAXN],r[MAXN];
int maxr[2*MAXN][4];
vector<pair<P,int> > save[2*MAXN];
void remove(int id){
    if(id==-1) return;
    u[id]=l[id]=d[id]=r[id]=-1;
}
void shrink(int id,int x){
    if(id==-1) return;
    u[id]=d[id]=x;
}
void shrink2(int id,int x){
    if(id==-1) return;
    r[id]=x;
    if(r[id]<=l[id]) remove(id);
}
void shrink3(int id,int x){
    if(id==-1) return;
    l[id]=x;
    if(r[id]<=l[id]) remove(id);
}
vector<int> dis;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        dis.clear();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&u[i],&l[i],&d[i],&r[i]); r[i]++;
            dis.push_back(l[i]); dis.push_back(r[i]);
        }
        sort(dis.begin(),dis.end()); dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(dis.begin(),dis.end(),l[i])-dis.begin()+1;
            r[i]=lower_bound(dis.begin(),dis.end(),r[i])-dis.begin()+1;
            int mask=0;
            if(u[i]==1&&d[i]==1) mask=1;
            else if(u[i]==2&&d[i]==2) mask=2;
            else mask=3;
            if(maxr[l[i]][mask]>=r[i]) remove(i);
            else
            {
                save[l[i]].push_back(make_pair(P(r[i],mask),i));
                maxr[l[i]][mask]=max(maxr[l[i]][mask],r[i]);
            }
        }
        int sz=(int)dis.size();
        int et1=0,et2=0,id1=-1,id2=-1;
        int ans=0;
        for(int i=1;i<=sz-1;i++){
            if(i==et1) {et1=0; id1=-1;}
            if(i==et2) {et2=0; id2=-1;}
            for(auto p:save[i]){
                if(p.F.S==1){
                    if(et1<=p.F.F&&id1!=id2){
                        shrink2(id1,i);
                        et1=p.F.F; id1=p.S;
                    }
                    else if(et1<=p.F.F){
                        if(et1==0) {et1=p.F.F; id1=p.S;}
                        else
                        {
                            if(maxr[et1][1]>=p.F.F) {remove(p.S); continue;}
                            shrink3(p.S,et1); maxr[et1][1]=max(maxr[et1][1],p.F.F);
                            save[et1].push_back(p); continue;
                        }
                    }
                    else remove(p.S);
                }
                else if(p.F.S==2){
                    if(et2<=p.F.F&&id1!=id2){
                        shrink2(id2,i);
                        et2=p.F.F; id2=p.S;
                    }
                    else if(et2<=p.F.F){
                        if(et2==0) {et2=p.F.F; id2=p.S;}
                        else
                        {
                            if(maxr[et1][2]>=p.F.F) {remove(p.S); continue;}
                            shrink3(p.S,et2); maxr[et2][2]=max(maxr[et2][2],p.F.F);
                            save[et2].push_back(p); continue;
                        }
                    }
                    else remove(p.S);
                }
                else{
                    if(et1<=p.F.F&&et2<=p.F.F){
                        shrink2(id1,i); shrink2(id2,i);
                        et1=et2=p.F.F; id1=id2=p.S;
                    }
                    else if(et1>p.F.F&&et2>p.F.F) remove(p.S);
                    else if(et1>p.F.F){
                        shrink(p.S,2); shrink2(id2,i);
                        et2=p.F.F; id2=p.S;
                    }
                    else{
                        shrink(p.S,1); shrink2(id1,i);
                        et1=p.F.F; id1=p.S;
                    }
                }
            }
            if(id1!=-1) ans+=dis[i]-dis[i-1];
            if(id2!=-1) ans+=dis[i]-dis[i-1];
           // printf("i=%d id1=%d id2=%d\n",i,id1,id2);
        }
        for(int i=1;i<=sz;i++) save[i].clear(); 
        for(int i=1;i<=sz;i++) maxr[i][1]=maxr[i][2]=maxr[i][3]=0;
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) if(u[i]==-1) printf("0 0 0 0\n"); else printf("%d %d %d %d\n",u[i],dis[l[i]-1],d[i],dis[r[i]-1]-1);
    }
    return 0;
}

