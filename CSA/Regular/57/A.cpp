#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int a[26];
char str[MAXN];
int main()
{
    scanf("%s",str);
    for(int i=0;i<26;i++)
        scanf("%d",&a[i]);
    int s=0,x=strlen(str);
    for(int i=0;i<x;i++)
        s+=a[str[i]-'a'];
    printf("%d\n",s);
    return 0;
}
