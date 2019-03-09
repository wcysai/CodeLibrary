#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int A,B;
bool grid[MAXN][MAXN];
void print()
{
    puts("100 100");
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++) 
            if(grid[i][j]) printf("#"); else printf(".");
        puts("");
    }
}
int main()
{
    scanf("%d%d",&A,&B);
    if(A==1)
    {
        memset(grid,false,sizeof(grid));
        for(int i=1;i<=100;i+=2)
            for(int j=1;j<=100;j+=2)
                if(B) grid[i][j]=true,B--;
    }
    else if(B==1)
    {
        memset(grid,true,sizeof(grid));
        for(int i=1;i<=100;i+=2)
            for(int j=1;j<=100;j+=2)
                if(A) grid[i][j]=false,A--;
    }
    else
    {
        memset(grid,false,sizeof(grid));
        for(int i=1;i<=100;i++) grid[50][i]=true;
        for(int i=52;i<=100;i++)
            for(int j=1;j<=100;j++)
                grid[i][j]=true;
        A-=2;B-=2;
        for(int i=1;i<49;i+=2)
            for(int j=1;j<=100;j+=2)
                if(B) grid[i][j]=true,B--;
        for(int i=53;i<=100;i+=2)
            for(int j=1;j<=100;j+=2)
                if(A) grid[i][j]=false,A--;
    }
    print();
    return 0;
}

