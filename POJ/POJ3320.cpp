#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN=1000000+10;
const int INF=0x3fffffff;
int a[MAXN];
set<int> s;
map<int,int> x;
int main()
{
  int p;
  while(~scanf("%d",&p))
  {
    for(int i=0;i<p;i++)
      scanf("%d",&a[i]);
    
    s.clear();
    for(int i=0;i<p;i++)
      s.insert(a[i]);
    int n=s.size();
    int s=0,t=0,ans=INF,cnt=0;
    while(true)
    {
      while(cnt<n && t<p)
      {
        if(x[ a[t++] ]++==0)
          cnt++;
      }
      if(cnt<n)  break;
      ans=min(ans,t-s);
      if(--x[a[s++]]==0)
        cnt--;		
    }
    printf("%d\n",ans);
  }
  return 0;
}