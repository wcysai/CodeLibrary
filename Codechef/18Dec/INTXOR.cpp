/*************************************************************************
    > File Name: INTXOR.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-14 18:33:38
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,ans[MAXN];
int ask(int i,int j,int k)
{
    printf("%d %d %d %d\n",1,i,j,k);
    fflush(stdout);
    int p;scanf("%d",&p);
    return p;
}
void find4(int x)
{
    static int ret[4];
    ret[0]=ask(x,x+1,x+2);
    ret[1]=ask(x+1,x+2,x+3);
    ret[2]=ask(x+2,x+3,x);
    ret[3]=ask(x+3,x,x+1);
    int xx=ret[0]^ret[1]^ret[2]^ret[3];
    ans[x]=xx^ret[1];
    ans[x+1]=xx^ret[2];
    ans[x+2]=xx^ret[3];
    ans[x+3]=xx^ret[0];
}
void find5(int x)
{
    static int ret[5];
    ret[0]=ask(x,x+1,x+2);
    ret[1]=ask(x+1,x+2,x+3);
    ret[2]=ask(x+2,x+3,x+4);
    ret[3]=ask(x+3,x+4,x);
    ret[4]=ask(x+4,x,x+1);
    int xx=ret[0]^ret[1]^ret[2]^ret[3]^ret[4];
    ans[x]=xx^ret[0]^ret[3];
    ans[x+1]=xx^ret[1]^ret[4];
    ans[x+2]=xx^ret[2]^ret[0];
    ans[x+3]=xx^ret[3]^ret[1];
    ans[x+4]=xx^ret[4]^ret[2];
}
void find7(int x)
{
    static int ret[7];
    ret[0]=ask(x,x+1,x+2);
    ret[1]=ask(x+1,x+2,x+3);
    ret[2]=ask(x+2,x+3,x+4);
    ret[3]=ask(x+3,x+4,x+5);
    ret[4]=ask(x+4,x+5,x+6);
    ret[5]=ask(x+5,x+6,x);
    ret[6]=ask(x+6,x,x+1);
    int xx=ret[0]^ret[1]^ret[2]^ret[3]^ret[4]^ret[5]^ret[6];
    ans[x+3]=xx^ret[0]^ret[4];
    ans[x+4]=xx^ret[1]^ret[5];
    ans[x+5]=xx^ret[2]^ret[6];
    ans[x+6]=xx^ret[3]^ret[0];
    ans[x]=xx^ret[4]^ret[1];
    ans[x+1]=xx^ret[5]^ret[2];
    ans[x+2]=xx^ret[6]^ret[3];
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        int now=1,rest=N;
        while(rest>0)
        {
            if(rest%4==0) {find4(now); now+=4; rest-=4;}
            else if(rest%4==1) {find5(now); now+=5; rest-=5;}
            else if(rest%4==2) {find5(now); find5(now+5); now+=10; rest-=10;}
            else {find7(now); now+=7; rest-=7;}
        }
        printf("2 ");
        for(int i=1;i<=N;i++) printf("%d%c",ans[i],i==N?'\n':' ');
        fflush(stdout);
        int ret;
        scanf("%d",&ret);
        assert(ret==1);
    }
    return 0;
}

