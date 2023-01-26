#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string A,B;
int main()
{
    cin>>n;
    cin>>A>>B;
    for(int i=0;i<n;i++) if(A[i]<B[i]) swap(A[i],B[i]);
    int x=0,y=0;
    for(int i=0;i<n;i++){
        x=(10LL*x+A[i]-'0')%MOD;
        y=(10LL*y+B[i]-'0')%MOD;
    }
    printf("%d\n",1LL*x*y%MOD);
    return 0;
}

