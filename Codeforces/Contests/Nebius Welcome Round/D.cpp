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
int n,m;
int l,r;
int get_low(string &s){
    int cnt=0;
    for(int i=0;i<(int)s.size();i++) cnt+=(s[i]-'0');
    int maxi=0,now=0;
    while(now<(int)s.size()-1){
        if(s[now]=='1'&&s[now+1]=='1'){
            maxi++;
            now+=2;
        }
        else now++;
    }
    maxi=min(maxi,m/4);
    return cnt-maxi;
}
int get_high(string &s){
    int cnt=0;
    for(int i=0;i<(int)s.size();i++) cnt+=(s[i]-'0');
    int maxi=0,now=0;
    while(now<(int)s.size()-1){
        if(s[now]!='1'||s[now+1]!='1'){
            maxi++;
            now+=2;
        }
        else now++;
    }
    maxi=min(maxi,m/4);
    return cnt-(m/4-maxi);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        l+=get_low(s); r+=get_high(s);
    }
    printf("%d %d\n",l,r);
    return 0;
}

