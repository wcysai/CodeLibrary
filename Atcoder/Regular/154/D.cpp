#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
mt19937 wcy(time(NULL));
int r[MAXN];
int one,ans[MAXN];
string str;
int ask(int a,int b,int c){
    printf("? %d %d %d\n",a,b,c); ifflush(stdout);
    cin>>str;
    if(str=="-1") assert(0);
    if(str.size()==2) return 0; else return 1;
}
bool cmp(int x,int y){
    return !ask(x,one,y);
}
int main()
{
    scanf("%d",&n);
    if(n==1){
        printf("! 1\n"); fflush(stdout); return 0;
    }
    memset(ans,-1,sizeof(ans));
    int x=-1,y=-1;
    while(true){
        int a,b;
        do{
            a=wcy()%n+1,b=wcy()%n+1;
        }while(a==b);
        if(!ask(a,a,b)) {x=a; y=b; break;}
    }
    one=-1;
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(i==x||i==y) continue;
        if(!ask(i,i,x)) v.push_back(i);
    }
    if(!v.size()){
        one=x;
    }
    else if(v.size()==1){
        one=v[0];
    }
    else
    {
        while(v.size()>1){
            int z=v[0];
            vector<int> vv; vv.clear();
            for(int i=1;i<(int)v.size();i++){
                if(!ask(v[i],v[i],z))
                    vv.push_back(v[i]);
            }
            if(!vv.size()){
                one=z; break;
            }
            else if(vv.size()==1){
                one=vv[0]; break;
            }
            vv.swap(v);
        }
    }
    ans[one]=1;
    for(int i=1;i<=n;i++) r[i]=i;
    for(int i=one;i<=n-1;i++) r[i]=r[i+1];
    sort(r+1,r+n,cmp);
    for(int i=1;i<=n-1;i++) ans[r[i]]=i+1;
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",ans[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}

