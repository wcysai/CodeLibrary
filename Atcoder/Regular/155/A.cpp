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
ll k;
string str;
bool check(string s){
    string t=s; reverse(t.begin(),t.end());
    return (s==t);
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>str;
        int res=k%(4*n);
        string rts=str; reverse(rts.begin(),rts.end());
        string x="";
        for(int i=0;i<res;i++){
            x+=((i/n)&1?str[i%n]:rts[i%n]);
        }
        if(check(str+x)&&check(x+str)) puts("Yes"); else puts("No");
    }
    return 0;
}

