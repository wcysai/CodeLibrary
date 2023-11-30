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
int n,k,p[MAXN];
int dep[MAXN],son[MAXN];
int cnt[MAXN];
bool f1=false,f2=false;
void read(){
    int x; 
    scanf("%d",&x);
    if(x==1) exit(0);
    assert(x!=-1); 
    for(int i=1;i<=k;i++){
        scanf("%d",&cnt[i]);
    }
}
vector<int> v;
int col[MAXN];
bool check_two(){
    for(int i=2;i<=n;i++){
        if(son[i]==1){
            int now=i;
            while(p[now]!=1) now=p[now];
            int need=(dep[i]&1?1:2);
            if(col[now]&&col[now]!=need) return false;
            col[now]=need;
        }
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    int d=0;
    for(int i=2;i<=n;i++) {scanf("%d",&p[i]); dep[i]=dep[p[i]]+1; son[p[i]]++; d=max(d,dep[i]);}
    if(d==1){
        k=1;
        printf("%d\n",1);
        for(int i=2;i<=n;i++) printf("%d%c",1,i==n?'\n':' '); 
        fflush(stdout);
        read();
        printf("%d\n",1); fflush(stdout);
        read(); assert(0);
    }
    else if(check_two()){
        k=2;
        printf("%d\n",2);
        for(int i=2;i<=n;i++) {
            if(dep[i]==1&&!col[i]) col[i]=1;
            else if(dep[i]>1) col[i]=3-col[p[i]];
            printf("%d%c",col[i],i==n?'\n':' ');
        }
        fflush(stdout);
        while(true){
            read();
            if(!cnt[2]||cnt[2]>=2) printf("%d\n",1);
            else if(!cnt[1]||cnt[1]>=2) printf("%d\n",2);
            else{
                printf("%d\n",1);
            }
            fflush(stdout);
        }
    }
    else{
        k=3;
        printf("%d\n",3);
        for(int i=2;i<=n;i++) {
            int x=dep[i]%3; if(x==0) x=3;
            printf("%d%c",x,i==n?'\n':' ');
        }
        fflush(stdout);
        while(true){
            read();
            if(cnt[1]&&cnt[2]) printf("%d\n",1);
            else if(cnt[2]&&cnt[3]) printf("%d\n",2);
            else if(cnt[1]&&cnt[3]) printf("%d\n",3);
            else{
                int x=0;
                for(int i=1;i<=3;i++) if(cnt[i]) x=i;
                printf("%d\n",x);
            }
            fflush(stdout);
        }
    }
    return 0;
}

