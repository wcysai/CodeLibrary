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
int t,n,k,a[MAXN];
string str[3];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<3;i++) cin>>str[i];
        vector<int> in[3],out[3];
        for(int i=0;i<3;i++) in[i].resize(n),out[i].resize(n);
        for(int j=0;j<3;j++)
            for(int i=0;i<n;i++){
                int x=j,y=(j+1)%3,z=(j+2)%3;
                if(i) {if(str[x][i-1]=='0') in[j][i]++; else out[j][i]++;}
                if(i!=n) {if(str[y][n-1-i]=='0') out[j][i]++; else in[j][i]++;}
                if(i) {if(str[z][n-1]=='0') out[j][i]++; else in[j][i]++;}
                if(i!=n) {if(str[z][n-1]=='0') in[j][i]++; else out[j][i]++;}
                printf("j=%d i=%d in=%d out=%d\n",j,i,in[j][i],out[j][i]);
            }
        vector<bool> bad(3*n,false); 
        for(int j=0;j<3;j++)
            for(int i=0;i<n;i++)
                if(!in[j][i]||!out[j][i]) bad[j*n+i]=true;
        int ans=0;
        for(int i=0;i<3*n;i++){
            int nxt=i+1; if(nxt==3*n) nxt=0;
            if(bad[i]&&bad[nxt]) {ans++; bad[i]=bad[nxt]=false;}
        }
        for(int i=0;i<3*n;i++) if(bad[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}

