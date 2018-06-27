#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define MAXN 20000
using namespace std;
char str[MAXN];
int x,y,z;
int main()
{
    scanf("%d %d %d",&x,&y,&z);
    scanf("%s",str);
    int a=0,b=0,c=0,m,n,p;
    int i=0,s=0,maxn=0;
    while(i<strlen(str))
    {
        if(str[i]=='R') a++;
        if(str[i]=='B') b++;
        if(str[i]=='Y') c++;
        s++;
        maxn=max(maxn,s);
        m=max(a-b,b-a);
        n=max(b-c,c-b);
        p=max(c-a,a-c);
        if((m==x&&n==y&&p==z)||(m==x&&n==z&&p==y)||(m==y&&n==x&&p==z)||(m==y&&n==z&&p==x)||(m==z&&n==x&&p==y)||(m==z&&n==y&&p==x))
        {
            s=0;
            a=0;
            b=0;
            c=0;
        }
        i++;
    }
    printf("%d\n",maxn);
    return 0;
}
