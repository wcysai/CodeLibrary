#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int e,s,n,m,k,a[MAXN];
P ans[MAXN];
int nxt[4][MAXN];
deque<int> stations[4];
P cost[MAXN];
vector<P> pos;//negative:station type, otherwise query id
int main(){
    scanf("%d%d%d%d",&e,&s,&n,&m);
    pos.push_back(P(e,-3));
    for(int i=1;i<=n;i++){
        int t,x;
        scanf("%d%d",&t,&x);
        if(x>=e) continue;
        pos.push_back(P(x,-t));
    }
    for(int i=1;i<=m;i++){
        int f;
        scanf("%d",&f);
        pos.push_back(P(f,i));
    }
    sort(pos.begin(),pos.end());
    for(int i=(int)pos.size()-1;i>=0;i--){
        for(int type=1;type<=3;type++) while(stations[type].size()&&pos[stations[type].front()].F-pos[i].F>s) stations[type].pop_front();
        if(i==(int)pos.size()-1){
            cost[i]=P(0,0);
        }
        else if(pos[i].S>0){
            if(e-pos[i].F<=s) ans[pos[i].S]=P(0,0);
            else{
                if(stations[3].size()){
                    ans[pos[i].S]=cost[stations[3].back()];
                }
                else{
                    if(stations[2].size()){
                        ans[pos[i].S]=cost[stations[2].front()];
                        if(ans[pos[i].S]!=P(-1,-1)) ans[pos[i].S].S-=(s-(pos[stations[2].front()].F-pos[i].F));
                    }
                    else if(stations[1].size()){
                        ans[pos[i].S]=cost[stations[1].front()];
                        if(ans[pos[i].S]!=P(-1,-1)) ans[pos[i].S].F-=(s-(pos[stations[1].front()].F-pos[i].F));
                    }
                    else ans[pos[i].S]=P(-1,-1);
                }
            }
        }
        else{
            int nearest=-1;
            for(int type=3;type>=-pos[i].S;type--){
                if(stations[type].size()){
                    if(nearest==-1||pos[stations[type].back()].F<pos[nearest].F) nearest=stations[type].back();
                }
            }
            if(nearest!=-1){
                cost[i]=cost[nearest]; int d=pos[nearest].F-pos[i].F;
                if(cost[i]!=P(-1,-1)){
                    if(pos[i].S==-1) cost[i].F+=d; else if(pos[i].S==-2) cost[i].S+=d;
                }
            }
            else{
                if(stations[2].size()){
                    cost[i]=cost[stations[2].front()];
                    if(cost[i]!=P(-1,-1)){
                        int d=pos[stations[2].front()].F-pos[i].F;
                        cost[i].S-=(s-d);
                    }
                }
                else if(stations[1].size()){
                    cost[i]=cost[stations[1].front()];
                    if(cost[i]!=P(-1,-1)) {
                        int d=pos[stations[1].front()].F-pos[i].F;
                        if(pos[i].S==-3) cost[i].F-=(s-d);
                        else {cost[i].F-=(s-d); cost[i].S+=s;}
                    }
                }
                else cost[i]=P(-1,-1);
            }
        }
        if(pos[i].S<0){
            stations[-pos[i].S].push_back(i);
        }
        //printf("i=%d S=%d pos=%d cost=%d %d\n",i,pos[i].S,pos[i].F,cost[i].F,cost[i].S);
    }
    for(int i=1;i<=m;i++) printf("%d %d\n",ans[i].F,ans[i].S);
    return 0;
}

