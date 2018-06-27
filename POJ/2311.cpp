#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<assert.h>
using namespace std;
const int MAX_WH=200;
int mem[MAX_WH+1][MAX_WH+1];
int grundy(int w,int h)
{
    if(mem[w][h]!=-1) return mem[w][h];
    set<int> s;
    for(int i=2;w-i>=2;i++) s.insert(grundy(i,h)^grundy(w-i,h));
    for(int i=2;h-i>=2;i++) s.insert(grundy(w,i)^grundy(w,h-i));
    int res=0;
    while(s.count(res)) res++;
    return mem[w][h]=res;
}
void solve(int w,int h)
{
    if(grundy(w,h)!=0) puts("WIN");
    else puts("LOSE");
}
int main()
{
    int n,m;
    memset(mem,-1,sizeof(mem));
    while(scanf("%d%d",&n,&m)==2)
        solve(n,m);
    return 0;
}
