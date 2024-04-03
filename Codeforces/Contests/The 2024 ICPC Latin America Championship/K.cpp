#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str[MAXN];
int dp[3],ndp[3];
bool vowel[26];
string mp="AEIOUY";
void upd(int &a,int b) {a=min(a,b);}
int get_res(int s,int id,int len){
    for(int i=0;i<len;i++){
        if(vowel[str[id][i]-'A']){
            s=0;
        }
        else{
            s++;
            if(s==3) return -1;
        }
    }
    return s;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    for(int i=0;i<6;i++) vowel[mp[i]-'A']=true;
    dp[1]=dp[2]=INF;
    for(int i=0;i<n;i++){
        ndp[0]=ndp[1]=ndp[2]=INF;
        for(int j=0;j<3;j++){
            if(dp[j]==INF) continue;
            for(int len=1;len<=min(3,(int)str[i].size());len++){
                int nxt=get_res(j,i,len);
            //    printf("len=%d nxt=%d\n",len,nxt);
                if(nxt!=-1) upd(ndp[nxt],dp[j]+len);
            }
        }
        swap(dp,ndp);
    }
    int ans=min(min(dp[0],dp[1]),dp[2]);
    if(ans==INF) puts("*"); else printf("%d\n",ans);
    return 0;
}

