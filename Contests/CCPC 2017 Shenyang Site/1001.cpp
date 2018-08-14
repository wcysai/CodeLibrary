#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
double pi[MAXN];
int main()
{
    int k=0;
    double s=0;
    for(int i=1;i<=100;i++)
    {
        s=s*16+((double)4/(8*k+1)-(double)2/(8*k+4)-(double)1/(8*k+5)-(double)1/(8*k+6));
        printf("%d %f\n",i,s);
        pi[i]=floor(s);
        s-=pi[i];
        printf("%d %c\n",i,pi[i]>=10?'A'-10+(int)pi[i]:'0'+(int)pi[i]);
        k++;
    }
    return 0;
}
