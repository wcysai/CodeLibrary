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
int T,n,k,a[MAXN];
string str;
void go(){
    string t="";
    for(int i=0;i<(int)str.size()-1;i++){
        if(str[i]=='A') t+=str[i+1];
    }
    for(int i=0;i<(int)str.size()-1;i++){
        if(str[i]=='B') t+=str[i+1];
    }
    str=t;
}
int main()
{
    /*cin>>str;
    while(str.size()>1){
        go();
        cout<<str<<endl;
    }*/
    scanf("%d",&T);
    while(T--){
        cin>>n>>str;
        bool hasB=false,hasAB=false;
        for(int i=0;i<(int)str.size();i++){
            if(str[i]=='B') hasB=true;
            if(i<(int)str.size()-1&&str[i]=='B'&&str[i+1]=='A') hasAB=true;
        }
        if(hasB&&!hasAB) puts("B"); else puts("A");
    }
    return 0;
}

