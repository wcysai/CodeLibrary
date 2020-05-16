#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(long long i=1;i<=n;++i)
#define bit(i) __builtin_popcountll(i)
#define LL long long
#define inf 998244353
#define F first
#define S second
#define N 500
#define maxn 500
using namespace std;
int n,m,d;
int g[N][N],du[N];
struct BPM {
  int n, m;               // å·¦å³é¡¶ç‚¹ä¸ªæ•°
  vector<int> G[maxn];    // é‚»æŽ¥è¡¨
  int left[maxn];         // left[i]ä¸ºå³è¾¹ç¬¬iä¸ªç‚¹çš„åŒ¹é…ç‚¹ç¼–å·ï¼Œ-1è¡¨ç¤ºä¸å­˜åœ¨
  bool T[maxn];           // T[i]ä¸ºå³è¾¹ç¬¬iä¸ªç‚¹æ˜¯å¦å·²æ ‡è®°

  int right[maxn];        // æ±‚æœ€å°è¦†ç›–ç”¨
  bool S[maxn];           // æ±‚æœ€å°è¦†ç›–ç”¨

  void init(int n, int m) {
    this->n = n;
    this->m = m;
    for(int i = 0; i < n; i++) G[i].clear();
  }

  void AddEdge(int u, int v) {
    G[u].push_back(v);
  }

  bool match(int u){
    S[u] = true;
    for(int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (!T[v]){
        T[v] = true;
        if (left[v] == -1 || match(left[v])){
          left[v] = u;
          right[u] = v;
          return true;
        }
      }
    }
    return false;
  }

  // æ±‚æœ€å¤§åŒ¹é…
  int solve() {
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));
    int ans = 0;
    for(int u = 0; u < n; u++) { // ä»Žå·¦è¾¹ç»“ç‚¹uå¼€å§‹å¢žå¹¿
      memset(S, 0, sizeof(S));
      memset(T, 0, sizeof(T));
      if(match(u)) ans++;
    }
    return ans;
  }

  // æ±‚æœ€å°è¦†ç›–ã€‚Xå’ŒYä¸ºæœ€å°è¦†ç›–ä¸­çš„ç‚¹é›†
  int mincover(vector<int>& X, vector<int>& Y) {
    int ans = solve();
    memset(S, 0, sizeof(S));
    memset(T, 0, sizeof(T));
    for(int u = 0; u < n; u++)
      if(right[u] == -1) match(u); // ä»Žæ‰€æœ‰Xæœªç›–ç‚¹å‡ºå‘å¢žå¹¿
    for(int u = 0; u < n; u++)
      if(!S[u]) X.push_back(u); // Xä¸­çš„æœªæ ‡è®°ç‚¹
    for(int v = 0; v < m; v++)
      if(T[v]) Y.push_back(v);  // Yä¸­çš„å·²æ ‡è®°ç‚¹
   return ans;
  }
}G;
int main()
{
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
    {
        int x,y; 
        scanf("%d%d",&x,&y);
        x--; y--;
        g[x][y]=g[y][x]=i;
        du[x]++;
        du[y]++;
    }
    while (1)
    {
        int mind=2147483647,maxd=-2147483647;
        for(int i=0;i<n;i++)mind=min(mind,du[i]);
        for(int i=0;i<n;i++)maxd=max(maxd,du[i]);
        //cout<<mind<<" "<<maxd<<endl;
        if (maxd<d)
        {
            puts("NO");
            return 0;
        }
        if (maxd==d || mind==d)break;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                if (g[i][j] && du[i]==maxd && du[j]==maxd)
                {
                    flag=1;
                    g[i][j]=g[j][i]=0;
                    du[i]--;
                    du[j]--;
                }
            if (flag)break;
        }
        if (flag)continue;
        G.init(n,n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if (du[i]==maxd && du[j]==mind)
                    G.AddEdge(i,j);
        G.solve();
        for(int i=0;i<n;i++)
            if (du[i]==maxd)
            {
                assert(G.right[i]!=-1);
                g[i][G.right[i]]=g[G.right[i]][i]=0;
                du[i]--;
                du[G.right[i]]--;
            }
    }
    puts("YES");
    static vector<int> ans; ans.clear();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if (g[i][j])ans.pb(g[i][j]);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto p:ans)printf("%d ",p);
    puts("");
}