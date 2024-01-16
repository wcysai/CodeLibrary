#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN],cnt[MAXN];
char str[MAXN];
int calc(int pos,int len){
    if(pos+len-1>n) return -1;
    if(len==1){
        if(str[pos]=='I') return 1; else return 5;
    }
    else if(len==2){
        if(str[pos]=='I'&&str[pos+1]=='V') return 4;
        else if(str[pos]=='V'&&str[pos+1]=='I') return 6;
        else if(str[pos]=='I'&&str[pos+1]=='I') return 2;
        else return -1;
    }
    else if(len==3){
        if(str[pos]=='I'&&str[pos+1]=='I'&&str[pos+2]=='I') return 3;
        else if(str[pos]=='V'&&str[pos+1]=='I'&&str[pos+2]=='I') return 7;
        else return -1;
    }
    else if(len==4){
        if(str[pos]=='V'&&str[pos+1]=='I'&&str[pos+2]=='I'&&str[pos+3]=='I') return 8;
        else return -1;
    }
    else return -1;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        n=strlen(str+1);
        cnt[n+1]=0;
        for(int i=n;i>=1;i--){
            cnt[i]=INF;
            for(int len=1;len<=4&&i+len-1<=n;len++) if(calc(i,len)!=-1) cnt[i]=min(cnt[i],cnt[i+len]+1);
        }
        int now=1;
        while(now<=n){
            int val=9,l=0;
            for(int len=1;len<=4&&now+len-1<=n;len++){
                int t=calc(now,len);
                if(t!=-1&&cnt[now+len]+1==cnt[now]&&t<val){
                    val=t; l=len;
                }
            }
            printf("%d",val);
            now+=l;
        }
        printf("\n");
    }
    return 0;
}

