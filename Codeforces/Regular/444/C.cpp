#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int face[25],p[25];
int n,k;
int rot[6][8]=
{
    {1,3,5,7,9,11,22,24},
    {2,4,6,7,10,12,21,23},
    {13,14,5,6,17,18,21,22},
    {15,16,7,8,19,20,23,24},
    {14,16,9,10,19,17,4,3},
    {13,15,11,12,20,18,2,1}
};
bool check()
{
    for(int i=0;i<6;i++)
    {
        if(p[i*4+1]==p[i*4+2]&&p[i*4+2]==p[i*4+3]&&p[i*4+3]==p[i*4+4]) continue;
        return false;
    }
    return true;
}
void ret()
{
    for(int i=1;i<=24;i++)
        p[i]=face[i];
}
void leftr(int x)
{
    int dummy[8];
    for(int i=0;i<6;i++)
        dummy[i]=face[rot[x][i+2]];
    dummy[6]=face[rot[x][0]];
    dummy[7]=face[rot[x][1]];
    for(int i=0;i<8;i++)
        p[rot[x][i]]=dummy[i];
}
void rightr(int x)
{
    int dummy[8];
    for(int i=2;i<8;i++)
        dummy[i]=face[rot[x][i-2]];
    dummy[0]=face[rot[x][6]];
    dummy[1]=face[rot[x][7]];
    for(int i=0;i<8;i++)
        p[rot[x][i]]=dummy[i];
}
int main()
{
    for(int i=1;i<=24;i++)
        scanf("%d",&face[i]);
    ret();
    for(int i=0;i<6;i++)
    {
        leftr(i);
        if(check())
        {
            printf("YES\n");
            return 0;
        }
        ret();
        rightr(i);
        if(check())
        {
            printf("YES\n");
            return 0;
        }
        ret();
    }
    printf("NO\n");
    return 0;
}

