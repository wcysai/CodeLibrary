#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> v;
        bool f=true;
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            v.push_back(x);
        }
        set<int> s; s.insert(INF+1);
        set<int> tmp;
        for(int i=0;i<(int)v.size();i++){
            set<int> new_tmp;
            for(auto x:tmp){
                ll z=1LL*x*v[i]/gcd(x,v[i]);
                if(z<=INF){
                    new_tmp.insert((int)z);
                    s.insert(z);
                }
            }
            new_tmp.insert(v[i]); s.insert(v[i]);
            swap(tmp,new_tmp);
        }
        int cnt=0;
        for(auto x:s){
            //printf("x=%d\n",x);
            cnt++;
            if(x!=cnt) break;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

