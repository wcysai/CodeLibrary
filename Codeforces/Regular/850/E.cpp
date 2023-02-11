#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char str[205];
int dp[205][9][9][9][4][4][4][4],ndp[205][9][9][9][4][4][4][4];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
P geta(int state){
    if(state==0) return P(0,1);
    else if(state==1) return P(1,0);
    else if(state==2) return P(0,3);
    else return P(1,0);
}
P getb(int state){
    if(state==0) return P(0,2);
    else if(state==1) return P(0,3);
    else if(state==2) return P(-1,0);
    else return P(-1,0);
}
bool vis[4];
int solve(int j,int s1,int s2,int s3,int t0,int t1,int t2,int t3){
    vis[0]=vis[1]=vis[2]=vis[3]=false;
    int now=0;
    vector<P> v;
    while(!vis[now]){
        vis[now]=true;
        int sum=0;
        if(now==0) sum+=j; else if(now==1) sum+=j+s1; else if(now==2) sum+=j+s2; else sum+=j+s3;
        v.push_back(P(sum,now));
        if(now==0) now=t0; else if(now==1) now=t1; else if(now==2) now=t2; else now=t3;
    }
    int sum=0;
    do{
        sum+=v.back().F; 
        if(v.back().S==now) break; else v.pop_back();
    }while(true);
    return sum;
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    dp[n/2][4][4][4][0][1][2][3]=1;
    for(int i=0;i<n;i++){
        memset(ndp,0,sizeof(ndp));
        for(int j=-i/2;j<=i/2;j++)
            for(int s1=-4;s1<=4;s1++)
                for(int s2=-4;s2<=4;s2++)
                    for(int s3=-4;s3<=4;s3++)
                        for(int t0=0;t0<=3;t0++)
                            for(int t1=0;t1<=3;t1++)
                                for(int t2=0;t2<=3;t2++)
                                    for(int t3=0;t3<=3;t3++){
                                        int &c=dp[j+n/2][s1+4][s2+4][s3+4][t0][t1][t2][t3];
                                        if(!c) continue;
                                        if(str[i+1]=='a'||str[i+1]=='?'){
                                            P x=geta(t0),y=geta(t1),z=geta(t2),w=geta(t3);
                                            add(ndp[j+x.F+n/2][s1+4+y.F-x.F][s2+4+z.F-x.F][s3+4+w.F-x.F][x.S][y.S][z.S][w.S],c);
                                        }
                                        if(str[i+1]=='b'||str[i+1]=='?'){
                                            P x=getb(t0),y=getb(t1),z=getb(t2),w=getb(t3);
                                            add(ndp[j+x.F+n/2][s1+4+y.F-x.F][s2+4+z.F-x.F][s3+4+w.F-x.F][x.S][y.S][z.S][w.S],c);
                                        }
                                    }
        swap(dp,ndp);
    }
    int ansa=0,ansb=0,anst=0;
    for(int j=-n/2;j<=n/2;j++)
        for(int s1=-4;s1<=4;s1++)
            for(int s2=-4;s2<=4;s2++)
                for(int s3=-4;s3<=4;s3++)
                    for(int t0=0;t0<=3;t0++)
                        for(int t1=0;t1<=3;t1++)
                            for(int t2=0;t2<=3;t2++)
                                for(int t3=0;t3<=3;t3++){
                                    int x=dp[j+n/2][s1+4][s2+4][s3+4][t0][t1][t2][t3];
                                    if(x){
                                        int y=solve(j,s1,s2,s3,t0,t1,t2,t3);
                                        printf("j=%d s1=%d s2=%d s3=%d t0=%d t1=%d t2=%d t3=%d x=%d y=%d\n",j,s1,s2,s3,t0,t1,t2,t3,x,y);
                                        if(y>0) add(ansa,x); else if(y==0) add(anst,x); else add(ansb,x);
                                    }
                                }
    printf("%d\n%d\n%d\n",ansa,anst,ansb);
    return 0;
}

