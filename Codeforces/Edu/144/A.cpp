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
int t,n;
string str;
int main()
{
    str="";
    for(int j=1;j<=200;j++){
        if(j%3==0) str+='F';
        if(j%5==0) str+='B';
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        string z;
        cin>>z;
        bool f=false;
        for(int i=0;i<=50;i++) if(z==str.substr(i,n)) f=true;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

