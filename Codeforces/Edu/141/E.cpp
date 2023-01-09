#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN];
int cnt[MAXN];
namespace fastIO {
  #define BUF_SIZE 100000
  //fread -> read
  bool IOerror = 0;
  inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if(p1 == pend) {
      p1 = buf;
      pend = buf + fread(buf, 1, BUF_SIZE, stdin);
      if(pend == p1){
        IOerror = 1;
        return -1;
      }
    }
    return *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template<typename T>
  inline void read(T &x) {
    char ch;
    while(blank(ch = nc()));
    if(IOerror)
      return;
    for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
  }
  #undef BUF_SIZE
};

using namespace fastIO;
int main()
{
    read(t);
    while(t--){
        read(n);
        int c=0;
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) read(b[i]);
        for(int i=0;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            if(a[i]<=b[i]) continue;
            else{
                c++;
                int d=a[i]-b[i]+1;
                int x=a[i]-d;
                cnt[a[i]]++;
                for(int j=1,p;j<=x;j=p+1){
                    int z=x/j;
                    p=x/z;
                    int r=p,l=max(d,(a[i]+z)/(z+1));
                    if(l<=r) {cnt[l]++; cnt[r+1]--; }
                }
            }
        }
        vector<int> ans;
        for(int i=1;i<=n;i++) {cnt[i]+=cnt[i-1]; if(cnt[i]==c) ans.push_back(i);}
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}
