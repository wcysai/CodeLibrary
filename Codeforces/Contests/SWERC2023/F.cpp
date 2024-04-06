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
map<string,int> mp;
string str[MAXN];
vector<P> vv;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str[i];
        int p;
        scanf("%d",&p);
        vector<int> v;
        for(int j=0;j<6;j++) {
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        p=p*10+v[1]+v[2]+v[3]+v[4];
        vv.push_back(P(p,-i));
    }
    sort(vv.begin(),vv.end(),greater<P>());
    vector<P> ans;
    for(int i=0;i<(int)vv.size();i++){
        if(i>0){
            if(vv[i-1].F!=vv[i].F&&i>2) break;
        }
        ans.push_back(vv[i]);
    }
    for(auto p:ans) {
        cout<<str[-p.S]<<" ";
        cout<<p.F<<endl;
    }
    return 0;
}

