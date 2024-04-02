#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,q,d,m,ans;
int zero[(1<<22)],one[(1<<22)];
int query(int x){
    int ans=0;
    int mask=x>>m,rmask=((~x)&((1<<d)-1))>>m;
    int z=x&((1<<m)-1),rz=(~x)&((1<<m)-1);
    for(int i=0;i<(1<<(d-m));i++){
        if(zero[(i<<m)+z]!=-1) ans=max(ans,((mask&i)<<m)+zero[(i<<m)+z]);
    }
    for(int i=0;i<(1<<(d-m));i++){
        if(one[(i<<m)+rz]!=-1) ans=max(ans,((rmask&i)<<m)+one[(i<<m)+rz]);
    }
    return ans;
}
void add(int x){
    int mask=x>>m,rmask=((~x)&((1<<d)-1))>>m;
    int z=x&((1<<m)-1),rz=(~x)&((1<<m)-1);
    //printf("x=%d z=%d rz=%d\n",x,z,rz);
    for(int i=0;i<(1<<m);i++){
        one[(mask<<m)+i]=max(one[(mask<<m)+i],i&z);
    }
    for(int i=0;i<(1<<m);i++){
        zero[(rmask<<m)+i]=max(zero[(rmask<<m)+i],i&rz);
        //printf("m=%d res=%d\n",(rmask<<m)+i,zero[(rmask<<m)+i]);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        d=2;
        while((1<<d)<n) d++;
        m=d/2; ans=0;
        for(int i=0;i<(1<<d);i++){
            zero[i]=one[i]=-1;
        }
        int last=0;
        for(int i=0;i<q;i++){
            int x;
            scanf("%d",&x);
            x=(x+last)%n;
            ans=max(ans,query(x));
            add(x);
            printf("%d ",ans);
            last=ans;
        }
        printf("\n");
    }
    return 0;
}

