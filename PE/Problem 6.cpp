#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s=5050*5050;
    for(int i=1;i<=100;i++)
        s-=i*i;
    printf("%d\n",s);
    return 0;
}
