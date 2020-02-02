#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 saddfkasod
#define y1 dksaodlasp
#define x2 daclspda
#define y2 dakosdsa
#define x3 dsalopdsa
#define y3 daslpdlap
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int dx[4]={0,1,1,0};
int dy[4]={0,0,1,1};
struct node
{
    int x1,y1,x2,y2,x3,y3;
};
vector<node> ans;
void query(int x1,int y1,int x2,int y2,int x3,int y3)
{
    ans.push_back((node){x1,y1,x2,y2,x3,y3});
}
void rotate_to(int x,int y,int id)
{
    for(int i=id+1;i<=id+3;i++)
    {
        int x1=x+dx[i%4],y1=y+dy[i%4];
        int x2=x+dx[id],y2=y+dy[id];
        int x3=x,y3=y;
        query(x1,y1,x2,y2,x3,y3);
    }
}
void print(node& p)
{
    printf("%c%d > %c%d ? %c%d\n",'a'+p.y1-1,p.x1,'a'+p.y2-1,p.x2,'a'+p.y3-1,p.x3);
}
int main()
{
    scanf("%d",&n);
    for(int i=n;i>=3;i--)
    {
        for(int j=n;j>=2;j--)
        {
            for(int row=1;row<i-1;row++)
                for(int col=n-1;col>=1;col--)
                    rotate_to(row,col,1);
            for(int col=1;col<=j-1;col++) rotate_to(i-1,col,2);
        }
        for(int row=1;row<i-1;row++)
            for(int col=n-1;col>=1;col--)
                rotate_to(row,col,1);
        query(i,2,i,1,i-1,1);
        query(i-1,2,i,2,i-1,1);
        query(i-1,1,i-1,2,i-1,1);
        rotate_to(i-2,1,1);
        query(i,1,i-1,1,i-1,1);
    }
    for(auto p:ans) print(p);
    return 0;
}