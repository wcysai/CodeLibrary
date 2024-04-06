#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int k,n,a[MAXN],b[MAXN];
int ans[4][MAXN];
vector<int> A,B,C,D,E,F;
//A: 3*3
//B: 2*3
//C: 2*2
//D: 1*3
//E: 1*2
//F: 1*1
int main(){
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    for(int i=1;i<=k;i++) {scanf("%d",&b[i]); if(b[i]<a[i]) swap(a[i],b[i]);}
    for(int i=1;i<=k;i++){
        if(a[i]==3) A.push_back(i);
        else if(a[i]==2&&b[i]==3) B.push_back(i);
        else if(a[i]==2&&b[i]==2) C.push_back(i);
        else if(b[i]==3) D.push_back(i);
        else if(b[i]==2) E.push_back(i);
        else F.push_back(i);
    }
    int now=1;
    for(auto x:A){
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                ans[i][now+j-1]=x;
        now+=3;
    }
    for(auto x:B){
        for(int i=1;i<=3;i++)
            for(int j=1;j<=2;j++)
                ans[i][now+j-1]=x;
        now+=2;
    }
    int sz=(int)C.size();
    for(auto x:C){
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                ans[i][now+j-1]=x;
        now+=2;
    }
    now-=2*sz;
    int sum=2*sz;
    while(sum>=3&&D.size()){
        if(sum==4&&E.size()>=2){
            int x=E.back(); E.pop_back();
            int y=E.back(); E.pop_back();
            ans[3][now]=ans[3][now+1]=x; ans[3][now+2]=ans[3][now+3]=y;
            now+=4; sum-=4; break; 
        }
        int x=D.back(); D.pop_back();
        ans[3][now]=ans[3][now+1]=ans[3][now+2]=x;
        now+=3; sum-=3;
    }
    while(sum>=2&&E.size()){
        int x=E.back(); E.pop_back();
        ans[3][now]=ans[3][now+1]=x;
        now+=2; sum-=2;
    }
    while(sum>=1&&F.size()){
        int x=F.back(); F.pop_back();
        ans[3][now]=x;
        now++; sum--;
    }
    assert(sum==0);
    while(D.size()){
        int x=D.back(); D.pop_back();
        ans[1][now]=ans[2][now]=ans[3][now]=x;
        now++;
    }
    while(E.size()>=3){
        int x=E.back(); E.pop_back(); int y=E.back(); E.pop_back(); int z=E.back(); E.pop_back();
        ans[1][now]=ans[2][now]=x;
        ans[1][now+1]=ans[2][now+1]=y;
        ans[3][now]=ans[3][now+1]=z;
        now+=2;
    }
    //printf("szE=%d\n",(int)E.size());
    while(E.size()){
        assert(F.size());
        int x=E.back(); E.pop_back(); int y=F.back(); F.pop_back();
        ans[1][now]=ans[2][now]=x; ans[3][now]=y;
        now++;
    }
  //  printf("sz=%d\n",(int)F.size());
    assert(F.size()%3==0);
    while(F.size()){
        int x=F.back(); F.pop_back(); int y=F.back(); F.pop_back(); int z=F.back(); F.pop_back();
        ans[1][now]=x; ans[2][now]=y; ans[3][now]=z;
        now++;
    }
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
            printf("%d%c",ans[i][j],j==n?'\n':' ');
    return 0;
}

