#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,A[MAXN],B[MAXN];
int fr[31];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++) scanf("%d",&A[i]);
        for(int i=1;i<=N;i++) scanf("%d",&B[i]);
        for(int j=0;j<30;j++) fr[j]=0;
        for(int i=1;i<=N;i++){
            if(i==1){
                for(int j=0;j<30;j++)
                    if(fr[j]!=2) fr[j]^=((A[i]>>j)&1);
            }
            else if(i==N){
                for(int j=0;j<30;j++)
                    if(fr[j]!=2) fr[j]^=((B[i]>>j)&1);
            }
            else{
                for(int j=0;j<30;j++){
                    int xa=(A[i-1]>>j)&1,xb=(A[i]>>j)&1,xc;
                    int ya=(B[i+1]>>j)&1,yb=(B[i]>>j)&1,yc;
                    if(xa==0&&xb==0) xc=0;
                    else if(xa==0&&xb==1) xc=1;
                    else xc=2;
                    if(ya==1&&yb==1) yc=1;
                    else if(ya==1&&yb==0) yc=0;
                    else yc=2;
                    if(xc==2&&yc==2) fr[j]=2; else if(fr[j]!=2)
                    {
                        if(xc!=2) fr[j]^=xc; else fr[j]^=yc;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<30;i++) 
            if(fr[i]) ans+=(1<<i);
        printf("%d\n",ans);
    }
    return 0;
}

