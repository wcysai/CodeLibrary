#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,m,a[MAXN];
char str[MAXN];
bool forbid[26];
string cur;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&m);
        scanf("%s",str+1);
        memset(forbid,false,sizeof(forbid));
        int cnt=k;
        cur="";
        for(int i=1;i<=m;i++){
            if(!forbid[str[i]-'a']){
                if(cnt==1){
                    cnt=k;
                    memset(forbid,false,sizeof(forbid));
                    cur+=str[i];
                }
                else {forbid[str[i]-'a']=true; cnt--;}
            }
            if(cur.size()==n) break;
        }
        if(cur.size()==n){
            puts("YES");
        }
        else{
            puts("NO");
            for(int i=0;i<k;i++) if(!forbid[i]) {cur+=(char)('a'+i); break;}
            while(cur.size()<n) cur+='a';
            cout<<cur<<endl;
        }
    }
    return 0;
}

