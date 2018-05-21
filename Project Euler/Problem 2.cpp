#include<bits/stdc++.h>
#define MAXN 4000000
using namespace std;
typedef long long ll;
int main()
{
    ll a=1,b=2,s=2;
    while(true)
    {
        b=a+b;
        a=b-a;
        if(b>MAXN) break;
        if(b%2==0) s+=b;
    }
    printf("%I64d\n",s);
    return 0;
}
