#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main(){
    cin>>str;
    int x=0;
    bool f=true;
    for(int i=0;i<(int)str.size();i++){
        if(str[i]=='A'){
            if(x!=0) f=false;
        }
        else if(str[i]=='B'){
            if(x==0||x==1) x=1;
            else f=false;
        }
        else if(str[i]=='C'){
            if(x==0||x==1||x==2) x=2;
            else f=false;
        }
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}

