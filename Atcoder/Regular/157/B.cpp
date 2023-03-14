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
int n,k;
char str[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    int cnt=0;
    for(int i=1;i<=n;i++) if(str[i]=='Y') cnt++;
    if(cnt==0) {printf("%d\n",max(0,k-1)); return 0;}
    if(cnt==n) {printf("%d\n",max(0,n-k-1)); return 0;}
    bool swapped=false;
    if(cnt+k>=n){
        k=cnt+k-n;
        vector<int> consec;
        int ans=n-1;
        int c=(str[1]=='Y'?1:0);
        bool fst=(str[1]=='Y'?true:false);
        int empt=0;
        for(int i=2;i<=n;i++){
            if(str[i]=='X'){
                if(fst){
                    empt+=c;
                    fst=false;
                    c=0;
                    continue;
                }
                consec.push_back(c);
                c=0;
            }
            else c++;
        }
        empt+=c;
        ans-=k;
        sort(consec.begin(),consec.end(),greater<int>());
        k=max(0,k-empt);
        int sum=0;
        for(int i=0;i<(int)consec.size();i++){
            if(sum<k) ans--; else break;
            sum+=consec[i];
        }
        printf("%d\n",max(ans,0));
        return 0;
    }
    vector<int> consec;
    int ans=0;
    int c=(str[1]=='X'?1:0);
    bool fst=(str[1]=='X'?true:false);
    for(int i=2;i<=n;i++){
        if(str[i]=='Y'){
            if(c==0) ans++; 
            else{
                if(fst){
                    fst=false;
                    c=0;
                    continue;
                }
                consec.push_back(c);
                c=0;
            }
        }
        else c++;
    }
    ans+=k;
    sort(consec.begin(),consec.end());
    int sum=0;
    for(int i=0;i<(int)consec.size();i++){
        sum+=consec[i];
        if(sum<=k) ans++; else break;
    }
    printf("%d\n",ans);
    return 0;
}

