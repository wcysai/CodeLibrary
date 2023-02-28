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
char s[MAXN],ans[MAXN];
int cnt[26];
int t;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        int n=strlen(s+1);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
        int l=1,r=n,f=0;
        for(int i=0;i<26;i++){
            while(cnt[i]){
                if(f){
                    ans[l]='a'+i;
                    cnt[i]--;
                    l++;
                }
                else if(cnt[i]>=2){
                    cnt[i]-=2;
                    ans[l]=ans[r]='a'+i;
                    l++; r--;
                }
                else{
                    int occ=-1,occ2=-1;
                    for(int j=i+1;j<26;j++){
                        if(occ==-1&&cnt[j]) occ=j;
                        else if(occ!=-1&&occ2==-1&&cnt[j]) occ2=j;
                    }
                    if(occ==-1){
                        ans[l]='a'+i; l++;
                        cnt[i]=0;
                    }
                    else if(occ2==-1){
                        while(cnt[occ]>=2)
                        {
                            ans[r]='a'+occ; ans[l]='a'+occ;
                            cnt[occ]-=2;
                            l++; r--;
                        }
                        ans[r]='a'+i; 
                        cnt[i]--; 
                        r--;
                    }
                    else{
                        ans[l]='a'+occ; ans[r]='a'+i;
                        l++; r--;
                        cnt[occ]--; cnt[i]--; 
                        f=1; 
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}

