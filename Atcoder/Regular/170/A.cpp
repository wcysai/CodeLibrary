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
string s,t;
vector<int> pos;
int main(){
    scanf("%d",&n);
    cin>>s; cin>>t;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]) pos.push_back(i);
    }
    if(!pos.size()) {puts("0"); return 0;}
    if(t[pos[0]]=='B'){
        int id=-1;
        for(int i=0;i<pos[0];i++) if(t[i]=='A') {id=i; break;}
        if(id==-1) {puts("-1"); return 0;}
        reverse(pos.begin(),pos.end());
        pos.push_back(id);
        reverse(pos.begin(),pos.end());
    }
    if(t[pos.back()]=='A'){
        int id=-1;
        for(int i=pos.back();i<n;i++) if(t[i]=='B') {id=i; break;}
        if(id==-1) {puts("-1"); return 0;}
        pos.push_back(id);
    }
    int ans=(int)pos.size(),cnt=0;
    for(auto x:pos){
        if(t[x]=='A') cnt++;
        else{
            if(cnt) {cnt--; ans--;}
        }
    }
    printf("%d\n",ans);
    return 0;
}

