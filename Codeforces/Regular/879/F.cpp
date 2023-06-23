#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,p[MAXN],r[MAXN];
int shift[MAXN],rshift[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) r[p[i]]=i,cnt[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++) 
        if(r[i]>i){
            ans++;
            cnt[r[i]-i]++;
        }
    shift[0]=ans;
    for(int i=1;i<=n-1;i++){
        if(i+(n-p[i])<=n) cnt[i+(n-p[i])]++;
        ans++;
        ans-=cnt[i];
        shift[i]=ans;
        //printf("i=%d shift=%d\n",i,shift[i]);
    }
    reverse(p+1,p+n+1);
    for(int i=1;i<=n;i++) r[p[i]]=i,cnt[i]=0;
    ans=0;
    for(int i=1;i<=n;i++) 
        if(r[i]>i){
            ans++;
            cnt[r[i]-i]++;
        }
    rshift[0]=ans;
    for(int i=1;i<=n-1;i++){
        if(i+(n-p[i])<=n) cnt[i+(n-p[i])]++;
        ans++;
        ans-=cnt[i];
        rshift[i]=ans;
    }
    printf("%d\n",shift[0]);
    int flag=0,s=0;
    scanf("%d",&q);
    while(q--){
        int type,x;
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&x); s=(s+x)%n;
        }
        else if(type==2){
            scanf("%d",&x); s=(s+n-x)%n;
        }
        else{
            flag^=1; s=(n-s)%n;
        }
        if(flag) printf("%d\n",rshift[s]); else printf("%d\n",shift[s]);
    }
    return 0;
}

