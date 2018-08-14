#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 1000005
using namespace std;
typedef long long ll;
char str[MAXN],save[MAXN];
int main()
{
    scanf("%s",str);
    int cnt=0;
    ll s=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='(') cnt++;
        if(str[i]==')') s+=cnt;
    }
    printf("%lld\n",s);
    return 0;
}
