#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXD 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
int n,d;
const double eps=1e-10;
vector<int> a[MAXN],b[MAXN];
vector<int> indices;
int fst[MAXN];
bool valid[MAXN];
vector<int> cur,ans;
bool cmp(int x,int y)
{
    return b[x]<b[y];
}
int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
    {
        int g=0;
        for(int j=0;j<d;j++)
        {
            int x;
            scanf("%d",&x);
            a[i].push_back(x);
            g=__gcd(g,x);
        }
        if(g==0) continue;
        for(int j=0;j<d;j++) a[i][j]/=g;
        fst[i]=d;
        for(int j=0;j<d;j++)
        {
            if(a[i][j]!=0)
            {
                fst[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        indices.clear();
        cur.clear();
        cur.push_back(i);
        for(int j=1;j<=n;j++)
        {
            if(j==i) continue;
            b[j]=a[j];
            if(fst[i]!=d&&b[j][fst[i]])
            {
                int pos=fst[i];
                int x=b[j][pos],y=a[i][pos];
                for(int k=0;k<d;k++) b[j][k]=b[j][k]*y-x*a[i][k];
            }
            int g=0;
            for(int k=0;k<d;k++) g=__gcd(g,b[j][k]);
            if(g==0)
            {
                cur.push_back(j); continue;
            }
            for(int k=0;k<d;k++) b[j][k]/=g;
            int sgn=0;
            for(int k=0;k<d;k++)
            {
                if(b[j][k]!=0)
                {
                    if(b[j][k]<0) sgn=-1;
                    else sgn=1;
                    break;
                }
            }
            if(sgn==-1)
            {
                for(int k=0;k<d;k++) b[j][k]*=-1;
            }
            indices.push_back(j);
        }
        sort(indices.begin(),indices.end(),cmp);
        int len=0,last=0,l=1,r=0;
        for(int i=0;i<(int)indices.size();i++)
        {
            if(i==0||b[indices[i]]==b[indices[i-1]])
            {
                if(i-last+1>len)
                {
                    l=last;
                    r=i;
                    len=i-last+1;
                }
            }
            else last=i;
        }
        if((int)indices.size()-last>len)
        {
            len=(int)indices.size()-last;
            l=last;
            r=(int)indices.size()-1;
        }
        if((int)cur.size()+len>(int)ans.size())
        {
            for(int i=l;i<=r;i++) cur.push_back(indices[i]);
            ans=cur;
        }
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}
/*
10 2
1 0
2 0
0 1
-3 1
-4 5
-5 4
6 -8
9 -1
100 -9
2131 -231
*/
