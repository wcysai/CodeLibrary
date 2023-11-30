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
int n,k,a[MAXN],tot;
string str;
map<string,int> id;
set<int> save[MAXN];
map<P,int> mp;
int get_id(string &str){
    if(id.find(str)==id.end()) id[str]=++tot;
    return id[str];
}
int find_period(){
    int n=(int)str.size();
    vector<int> nxt(n+1,0);
    for(int i=1;i<n;i++){
        int j=i;
        while(j){
            j=nxt[j];
            if(str[j]==str[i]) {
                nxt[i+1]=j+1;
                break;
            }
        }
    }
    return (n%(n-nxt[n])==0)?(n-nxt[n]):n;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>str;
        int x=find_period();
        int cnt=(int)str.size()/x;
        str=str.substr(0,x);
        int id=get_id(str);
        int now=max(cnt,mp[P(id,cnt)]);
        while(save[id].count(now)) now+=cnt;
        printf("%d ",now/cnt);
        save[id].insert(now);
        mp[P(id,cnt)]=now;
    }
    return 0;
}

