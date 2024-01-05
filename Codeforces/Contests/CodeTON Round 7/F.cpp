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
int t,n,k,a[MAXN];
char str[MAXN];
char s[MAXN];
vector<string> v;
int main(){
    scanf("%d",&t);
    while(t--){
        v.clear();
        scanf("%d",&n);
        scanf("%s",str+1);
        int flip=0,l=1,r=2*n;
        string tt(n,'0');
        while(l<=r){
            if(str[l]==str[r]){
                if(!flip){
                    str[l]='0'+'1'-str[l];
                    str[r]='0'+'1'-str[r];
                }
                flip^=1;
                tt[l-1]='('; tt[r-1]=')';
                l++; r--;
            }
            else{
                if(!flip){
                    str[l]='0'+'1'-str[l];
                    str[l+1]='0'+'1'-str[l+1];
                }
                tt[l-1]='('; tt[l]=')';
                l+=2;
            }
        }
        v.push_back(tt);
        for(int i=1;i<=n;i++) if(str[i]!=str[2*n+1-i]) f=false;
        if(str[1]!='1'){

        }
        for(int i=1;i<=n;i++){
            if(str[i]!=str[n+1-i]){
                f=true;
            }
        }
        printf("%d\n",3);
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++) printf("%c",s[i][j]);
            printf("\n");
        }
    }
    return 0;
}

