#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dojadkoa
#define y1 dsaijdakji
#define x2 dsajdiosa
#define y2 diaodsdsa
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,q;
char str[MAXN][MAXN];
int s[MAXN][MAXN];
int sum[MAXN][MAXN];
int row[MAXN][MAXN];
int col[MAXN][MAXN];
void prefix_sum(int a[][MAXN])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]+=a[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]+=a[i-1][j];
}
int compute_area(int a[][MAXN],int x1,int y1,int x2,int y2)
{
    return a[x2][y2]+a[x1-1][y1-1]-a[x1-1][y2]-a[x2][y1-1]; 
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) 
    {
        scanf("%s",str[i]+1);
        for(int j=1;j<=m;j++) sum[i][j]=s[i][j]=str[i][j]-'0';
    }
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]&&s[i+1][j]) row[i][j]++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-1;j++)
            if(s[i][j]&&s[i][j+1]) col[i][j]++;
    prefix_sum(sum);prefix_sum(row);prefix_sum(col);
    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",compute_area(sum,x1,y1,x2,y2)-compute_area(row,x1,y1,x2-1,y2)-compute_area(col,x1,y1,x2,y2-1));
    }
    return 0;
}

