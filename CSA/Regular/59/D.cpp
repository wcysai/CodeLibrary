#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,w,h;
int l[MAXN],next[MAXN];
int main()
{
    scanf("%d%d%d",&n,&w,&h);
    for(int i=0;i<n;i++)
        scanf("%d",&l[i]);
    int curr=0,k=0,j=0;
    while(k<n)
    {
        if(current+l[j]>w)
        {
            next[k]=j-1;
            cur-=l[k]+1;
        }
    }

}
