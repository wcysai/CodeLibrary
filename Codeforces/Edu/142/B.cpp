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
int t,a,b,c,d;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(!a){
            puts("1"); continue;
        }
        else{
            int x=min(b,c),ans=2*x+a;
            b-=x; c-=x;
            if(c) swap(b,c);
            printf("%d\n",ans+min(a+1,b+d));
        }
    }
    return 0;
}

