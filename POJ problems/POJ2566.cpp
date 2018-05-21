#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
using namespace std;
const int maxn=100005;
const int INF=INT_MAX;
int n,m;
pair<int,int>p[maxn];
inline int fab(int x){return x>0?x:-x;}
void query(int t)
{
    int i=0,j=1,k,ans=INF,v,l,r,tmp;
    while(j<n&&ans)
    {
          tmp=p[j].first-p[i].first;
          k=abs(t-tmp);
          if(k<ans)
          {
             ans=k;
             v=tmp;
             l=p[i].second;
             r=p[j].second;
             }
          if(tmp<t)j++;
          if(tmp>t)i++;
          if(i==j)j++;
          }
    if(l>r){k=l;l=r;r=k;}
    printf("%d %d %d\n",v,l+1,r);
    }
int main()
{
    int i,j,k,sum,x,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
          if(n==0&&m==0)break;
          p[0]=make_pair(0,0);
          sum=0;
          for(i=1;i<=n;i++)
          {
              scanf("%d",&x);
              sum+=x;
              p[i]=make_pair(sum,i);
              }
          n++;
          sort(p,p+n);
          while(m--)
          {
                scanf("%d",&t);
                query(t);
                }
          }
    return 0;
    }
