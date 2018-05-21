#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;
int main()
{
    int s=0;
    for(int i=3;i<MAXN;i++)
        if(i%3==0||i%5==0) s+=i;
    printf("%d\n",s);
    return 0;
}
