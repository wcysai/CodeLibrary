#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,p[MAXN];
int label[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        bool f=true;
        for(int i=1;i<=n;i++) if(p[i]!=i) f=false;
        if(f) {puts("1"); continue;}
        for(int i=1;i<=n+1;i++) label[i]=0;
        int tot=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(!label[i]){
                cnt++;
                vector<int> tmp;
                int now=i; tmp.push_back(i); label[i]=++tot;
                while(!label[p[now]]){
                    now=p[now];
                    label[now]=tot;
                    tmp.push_back(now);
                }
                for(auto x:tmp) if(label[x+1]==label[x]) f=true;
            }
        }
        printf("%d\n",f?n-cnt-1:n-cnt+1);
    }
    return 0;
}

