#include<bits/stdc++.h>
#define MAXN 10000005
using namespace std;
int k[MAXN],n,t;
int main()
{
    scanf("%d",&t);
    k[1]=1;
    k[2]=2;
    int i=2,j=2;
    while(j<MAXN)
    {
        int p=j+k[i]-1;
        int q=k[j-1];
        while(j<=min(MAXN-1,p))
        {
            if(q==1) k[j]=2; else k[j]=1;
            j++;
        }
        i++;
    }
    for(int q=0;q<t;q++)
    {
    scanf("%d",&n);
    printf("%d\n",k[n]);
    }
    return 0;

}
