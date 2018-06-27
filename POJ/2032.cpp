#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<deque>
#include<assert.h>
#define MAXN 16
#define INF 1000000000
using namespace std;
int mp[MAXN][MAXN],sqr[MAXN][MAXN];
int n,min_res;
void construct_sqr(int a[MAXN][MAXN])
{
    int len[MAXN][MAXN],height[MAXN][MAXN];
    memset(len,0,sizeof(len));
    memset(height,0,sizeof(height));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(j==0) len[i][j]=a[i][j]; else len[i][j]=a[i][j]==0?0:len[i][j-1]+1;
    for(int j=0;j<n;j++)
        for(int i=0;i<n;i++)
            if(i==0) height[i][j]=a[i][j]; else height[i][j]=a[i][j]==0?0:height[i-1][j]+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            sqr[i][j]=0;
            for(int k=1;k<n;k++)
            {
                if(i-k+1<0||j-k+1<0) break;
                bool f=true;
                for(int p=0;p<k;p++)
                    if(len[i-p][j]<k) {f=false;break;}
                if(!f) break;
                sqr[i][j]=k;
            }
        }
}
int hstar(int a[MAXN][MAXN])
{
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            bool f=true;
            if(sqr[i][j]==0) f=false;
            if(i<n-1&&a[i+1][j]>a[i][j]) f=false;
            if(j<n-1&&a[i][j+1]>a[i][j]) f=false;
            if(i<n-1&&j<n-1&&a[i+1][j+1]>a[i][j]) f=false;
            if(f) cnt++;
        }
    return cnt;
}
int dfs(int a[MAXN][MAXN],int num,int ans)
{
    construct_sqr(a);
    int cpy[MAXN][MAXN];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cpy[i][j]=sqr[i][j];
    if(ans+hstar(cpy)>=min_res) return INF;
    if(ans==0) return min_res=ans;
    int res=INF;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cpy[i][j]>=0)
            {
                for(int k)
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mp[i][j]);
    printf("%d\n",hstar(mp));
    return 0;
}
