#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int maxn=1e6+10;
int vis[maxn];
int T,n,k,x,cnt,odd,even;
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&k);
        int N=(n+k)*2+5;
        for (int i=0;i<=N;i++) vis[i]=0;
        while (n--){
            scanf("%d",&x);
            vis[x]=1;
        }
        cnt=k;
        for (int i=0;i<=N;i+=2){
            if (!vis[i]){
                if (cnt>0) cnt--;
                else {
                    even=i;
                    break;
                }
            }
        }
        cnt=k;
        for (int i=1;i<=N;i+=2){
            if (!vis[i]){
                if (cnt>0) cnt--;
                else {
                    odd=i;
                    break;
                }
            }
        }
        if (even<odd){
            puts("Alice");
        } else {
            puts("Bob");
        }
    }
    return 0;
}