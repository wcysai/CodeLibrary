#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll a[MAXN];
int cnt[10],ccnt[10];
P calc(){
    int res=INF,id=0;
    for(int t=0;t<=9;t++){
        int s=0;
        for(int i=0;i<=9;i++){
            s+=cnt[i]*((t+i)%10);
            s+=ccnt[i]*(((t+i)%10)+((t+i)>=10?1:0));
        }
        if(s<res) {res=s; id=t;}
    }
    return P(id,res);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll x=1,ans=0;
    for(int i=0;i<=11;i++){
        memset(cnt,0,sizeof(cnt)); memset(ccnt,0,sizeof(ccnt));
        for(int j=1;j<=n;j++) {if(a[j]<10*x) ccnt[(a[j]/x)%10]++; else cnt[(a[j]/x)%10]++;}
        P p=calc();
        for(int j=0;j<=9;j++) printf("%d%c",cnt[j],j==9?'\n':' ');
        for(int j=0;j<=9;j++) printf("%d%c",ccnt[j],j==9?'\n':' ');
        printf("i=%d F=%d S=%d\n",i,p.F,p.S);
        ans+=p.S;
        for(int j=1;j<=n;j++) a[j]+=(p.F*x);
        x*=10;
    }
    printf("%lld\n",ans);
    return 0;
}

