#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
char x;
int a[6];
int main()
{
    int cnt=0,k=0;
   while (cin>>x)
    {
        switch(x)
        {
    case '(':
        a[0]++;
        break;
            case '[':
        a[1]++;
        break;
            case '{':
        a[2]++;
        break;
           case ')':
        a[3]++;
        break;
            case ']':
        a[4]++;
        break;
            case '}':
        a[5]++;
        break;
            default:
                break;
    }
    }
    if(a[0]==a[3]&&a[1]==a[4]&&a[2]==a[5])  printf("%d\n",a[0]+a[1]+a[2]); else printf("0\n");
    return 0;
}
