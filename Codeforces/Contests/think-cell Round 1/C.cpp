#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int bit[MAXN];
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> dis;
        set<int> s;
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]+=i;
            if(!s.count(a[i])) s.insert(a[i]); else mp[a[i]]++;
        }
        int last=INF;
        vector<P> v;
        for(auto p:mp) v.push_back(p);
        reverse(v.begin(),v.end());
        for(auto p:v){
            int now=min(last,p.F-1),cnt=p.S;
            while(cnt){
                while(s.count(now)) now--;
                s.insert(now);
                cnt--;
            }
            last=now-1;
        }
        for(auto it=s.rbegin();it!=s.rend();it++){
            printf("%d ",*it);
        }
        printf("\n");
    }
    return 0;
}

