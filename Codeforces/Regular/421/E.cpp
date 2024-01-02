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
int n,k,a[MAXN];
vector<vector<int> > ans;
void init(int x){
    if(x==3){
        vector<int> v; v.push_back(1); v.push_back(2); v.push_back(3);
        ans.push_back(v);
        ans.push_back(v);
    }
    else{
        vector<int> v;
        for(int i=1;i<=4;i++){
            int now=i; v.clear();
            for(int j=0;j<3;j++){
                v.push_back(now);
                now++;
                if(now>4) now-=4;
            }
            ans.push_back(v);
        }

    }
}
void update(int x){
    int s=x-1,t=x;
    vector<vector<int> > tmp;
    for(int i=1;i<=x-1;i++){
        vector<int> v;
        if(i<=x-2) v.push_back(i);   
        tmp.push_back(v);
    }
    for(int i=0;i<(int)tmp.size();i++){
        int nxt=(i==(int)tmp.size()-1?0:i+1);
        vector<int> v;
        v.push_back(s);
        for(int j=0;j<(int)tmp[i].size();j++) v.push_back(tmp[i][j]);
        v.push_back(t);
        for(int j=(int)tmp[nxt].size()-1;j>=0;j--) v.push_back(tmp[nxt][j]);
        ans.push_back(v);
    }
}
int main(){
    scanf("%d",&n);
    int st=n&1?3:4;
    init(st);
    for(int i=st+2;i<=n;i+=2) update(i);
    printf("%d\n",(int)ans.size());
    for(auto x:ans){
        printf("%d",(int)x.size());
        for(auto y:x) printf(" %d",y);
        printf("\n");
    }
    return 0;
}

