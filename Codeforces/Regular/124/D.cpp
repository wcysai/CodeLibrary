#include<bits/stdc++.h>
#define MAXN 400005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
vector<pair<int&,int> > backup;
int n,d;
char str[MAXN];
void modify(int &a,int b){
    backup.push_back({a,a});
    a=b;
}
void rollback(int t){
    while(backup.size()>t){
        backup.back().F=backup.back().S;
        backup.pop_back();
    }
}
struct PAM{
    int s[MAXN],now;
    int nxt[MAXN][26],fail[MAXN],l[MAXN],last,tot;
    void clear(){ //1: odd root 0: even root
        s[0]=l[1]=-1;
        fail[0] = tot = now =1;
        last = l[0]=0;
        memset(nxt[0],0,sizeof(nxt[0]));
        memset(nxt[1],0,sizeof(nxt[1]));
    }
    PAM(){clear();}
    int newnode(int len){
        modify(tot,tot+1);
        //memset(nxt[tot],0,sizeof(nxt[tot]));
        modify(fail[tot],0);
        modify(l[tot],len);
        return tot;
    }
    int get_fail(int x){
        while (s[now-l[x]-2]!=s[now-1]) x=fail[x];
        return x;
    }
    void add(int ch){
        modify(s[now],ch);
        modify(now,now+1);
        int cur = get_fail(last);
        if(!nxt[cur][ch]){
            int tt = newnode(l[cur]+2);
            modify(fail[tt],nxt[get_fail(fail[cur])][ch]);
            modify(nxt[cur][ch],tt);
        }
        modify(last,nxt[cur][ch]);
    }
}pam;
char ans[MAXN];
int save[MAXN];
int main(){
    scanf("%d",&d);
    scanf("%s",str+1); n=strlen(str+1);
    bool larger=false,flag=true;
    int last=n;
    for(int i=1;i<=n;i++){
        save[i]=(int)backup.size();
        if(!flag) break;
        for(int j=0;j<27;j++){
            if(j==26){
                last=i-1;
                flag=false;
                break;
            }
            if(!larger&&'a'+j<str[i]) continue;
            pam.add(j);
            if(pam.l[pam.last]>=d) rollback(save[i]);
            else {
                if('a'+j>str[i]) larger=true;
                ans[i]='a'+j; break;
            }
        }
    }
    if(!flag||!larger){
        larger=false; 
        bool success=false; int id=-1;
        for(int i=last;i>=1;i--){
            if(success) break;
            rollback(save[i]);
            for(int j=str[i]-'a'+1;j<26;j++){
                pam.add(j);
                if(pam.l[pam.last]>=d) rollback(save[i]);
                else {
                    success=true; id=i;
                    ans[i]='a'+j; break;
                }
            }
        }
        if(!success) {puts("Impossible"); return 0;}
        for(int i=id+1;i<=n;i++){
            save[i]=(int)backup.size();
            for(int j=0;j<26;j++){
                pam.add(j);
                if(pam.l[pam.last]>=d) rollback(save[i]);
                else {
                    ans[i]='a'+j; break;
                }
            }
        }
        printf("%s\n",ans+1);
    }
    else printf("%s\n",ans+1);
    return 0;
}

