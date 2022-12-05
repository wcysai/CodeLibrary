#include<bits/stdc++.h>
using namespace std;
const int M=1000000009;
map<string,int> f[155][155],g[155][155];
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
int T,n,s[155];
string S[155][155];
bool ispalindrome(string &a){
    int len=a.size();
    for (int i=0;i<len/2;i++) if (a[i]!=a[len-1-i]) return 0;
    return 1;
}
int G(int l,int r,string a);
int F(int l,int r,string a){
    if (l==r+1){
        if (ispalindrome(a)) return 1; else return 0;
    }
    if (f[l][r].find(a)!=f[l][r].end()) return f[l][r][a];
    int &ret=f[l][r][a];
    int x=a.size();
    for (int p=l;p<=r;p++){
        string &b=S[p][r];
        int y=b.size();
        if (y<x){
            bool flag=1;
            for (int i=0;i<y;i++) 
                if (a[i]!=b[y-1-i]){
                    flag=0;
                    break;
                }
            if (flag){
                string aa="";
                for (int i=y;i<x;i++) aa+=a[i];
                add(ret,F(l,p-1,aa));
            }
        } else {
            bool flag=1;
            for (int i=0;i<x;i++)
                if (a[i]!=b[y-1-i]){
                    flag=0;
                    break;
                }
            if (flag){
                string aa="";
                for (int i=0;i<y-x;i++) aa+=b[i];
                add(ret,G(l,p-1,aa));
            }
        }
    }
    return ret;
}
int G(int l,int r,string a){
    if (l==r+1){
        if (ispalindrome(a)) return 1; else return 0;
    }
    if (g[l][r].find(a)!=g[l][r].end()) return g[l][r][a];
    int &ret=g[l][r][a];
    int x=a.size();
    for (int p=l;p<=r;p++){
        string &b=S[l][p];
        int y=b.size();
        if (y<=x){
            bool flag=1;
            for (int i=0;i<y;i++) 
                if (b[i]!=a[x-1-i]){
                    flag=0;
                    break;
                }
            if (flag){
                string aa="";
                for (int i=0;i<x-y;i++) aa+=a[i];
                add(ret,G(p+1,r,aa));
            }
        } else {
            bool flag=1;
            for (int i=0;i<x;i++)
                if (b[i]!=a[x-1-i]){
                    flag=0;
                    break;
                }
            if (flag){
                string aa="";
                for (int i=x;i<y;i++) aa+=b[i];
                add(ret,F(p+1,r,aa));
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&s[i]);
        for (int i=2;i<=n;i++) s[i]+=s[i-1];
        for (int i=1;i<=n;i++)
            for (int j=i;j<=n;j++){
                f[i][j].clear(),g[i][j].clear();
                int sum=s[j]-s[i-1];
                S[i][j]="";
                if (sum==0) S[i][j]+='0';
                while (sum){
                    S[i][j]+=(char)('0'+sum%10);
                    sum/=10;
                }
                reverse(S[i][j].begin(),S[i][j].end());
            }
        printf("%d\n",G(1,n,""));
    }
    return 0;
}