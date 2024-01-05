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
int n,k,a[MAXN];
char ch[4][4];
string ans;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
bool check(int x,int y,int z){
    if(max(x/3-y/3,y/3-x/3)>1) return false;
    if(max(z/3-y/3,y/3-z/3)>1) return false;
    if(max(x%3-y%3,y%3-x%3)>1) return false;
    if(max(z%3-y%3,y%3-z%3)>1) return false;
    return true;
}
int main(){
    for(int i=0;i<3;i++) scanf("%s",ch[i]);
    ans="CCC";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i==j) continue;
            for(int k=0;k<9;k++){
                if(i==k||j==k) continue;
                if(check(i,j,k)){
                    string str="";
                    str+=ch[i/3][i%3];
                    str+=ch[j/3][j%3];
                    str+=ch[k/3][k%3];
                    ans=min(ans,str);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;

}

