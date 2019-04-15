#include<bits/stdc++.h>
#define MAXN 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
//1: white king, 2,3: white bishop, 4: black king
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int turn;
struct piece
{
    int x,y;
}wking,bking,bishop[2];
bool haspiece(int x,int y)
{
    if(x==wking.x&&y==wking.y) return true;
    if(x==bking.x&&y==bking.y) return true;
    if(x==bishop[0].x&&y==bishop[0].y) return true;
    if(x==bishop[1].x&&y==bishop[1].y) return true;
    return false;
}
bool whitecheck(int x,int y)
{
    if(abs(x-wking.x)<=1&&abs(y-wking.y)<=1) return true;
    for(int id=0;id<=1;id++)
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
            {
                if(!dx||!dy) continue;
                for(int k=1;k<=7;k++)
                {
                    int nx=bishop[id].x+k*dx,ny=bishop[id].y+k*dy;
                    if(nx<1||nx>8||ny<1||ny>8) continue;
                    if(nx==x&&ny==y) return true;
                    if(haspiece(nx,ny)) break;
                }
            }
    return false;
}
bool blackcheck(int x,int y)
{
    if(abs(x-bking.x)<=1&&abs(y-bking.y)<=1) return true;
    return false;
}
bool hasbishop(int x,int y)
{
    if(x==bishop[0].x&&y==bishop[0].y) return true;
    if(x==bishop[1].x&&y==bishop[1].y) return true;
    return false;
}
bool movepiece(int turn,int magic)
{
    if(magic==0) return false;
    if(!turn)
    {
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
            {
                if(!dx&&!dy) continue;
                int nx=wking.x+dx,ny=wking.y+dy;
                if(nx<1||nx>8||ny<1||ny>8) continue;
                if(blackcheck(nx,ny)) continue;
                if(haspiece(nx,ny)) continue;
                wking.x+=dx; wking.y+=dy;
                if(!movepiece(!turn,magic-1)) {wking.x-=dx; wking.y-=dy; return false;}
                wking.x-=dx; wking.y-=dy;
            }
        for(int id=0;id<=1;id++)
            for(int dx=-1;dx<=1;dx++)
                for(int dy=-1;dy<=1;dy++)
                {
                    if(!dx||!dy) continue;
                    for(int k=1;k<=7;k++)
                    {
                        int nx=bishop[id].x+k*dx,ny=bishop[id].y+k*dy;
                        if(nx<1||nx>8||ny<1||ny>8) continue;
                        if(blackcheck(nx,ny)) continue;
                        if(haspiece(nx,ny)) break;
                        bishop[id].x+=k*dx; bishop[id].y+=k*dy;
                        if(!movepiece(!turn,magic-1)) {bishop[id].x-=k*dx; bishop[id].y-=k*dy; return false;}
                        bishop[id].x-=k*dx; bishop[id].y-=k*dy;
                    }
                }
        return true;
    }
    else
    {
        bool hasmove=false;
        for(int dx=-1;dx<=1;dx++)
            for(int dy=-1;dy<=1;dy++)
            {
                if(!dx&&!dy) continue;
                int nx=bking.x+dx,ny=bking.y+dy;
                if(nx<1||nx>8||ny<1||ny>8) continue;
                if(whitecheck(nx,ny)) continue;
                if(hasbishop(nx,ny)) return true;
                else if(haspiece(nx,ny)) continue;
                bking.x+=dx; bking.y+=dy;
                hasmove=true;
                if(movepiece(!turn,magic-1)) {bking.x-=dx; bking.y-=dy; return true;}
                bking.x-=dx; bking.y-=dy;
            }
        if(!hasmove)
        {
            if(whitecheck(bking.x,bking.y)) return false;
            return true;
        }
        return false;
    }
}
int main()
{
    freopen("bishops.in","r",stdin);
    freopen("bishops.out","w",stdout);
    cin>>str; wking.x=str[0]-'a'+1; wking.y=str[1]-'0'; 
    cin>>str; bishop[0].x=str[0]-'a'+1; bishop[0].y=str[1]-'0'; 
    cin>>str; bishop[1].x=str[0]-'a'+1; bishop[1].y=str[1]-'0'; 
    cin>>str; bking.x=str[0]-'a'+1; bking.y=str[1]-'0'; 
    cin>>str; turn=(str=="black");
    if(((bishop[0].x+bishop[0].y)&1)==((bishop[1].x+bishop[1].y)&1))
    {
        puts("draw");
        return 0;
    }
    if(movepiece(turn,3)) puts("draw"); else puts("white wins");
}
