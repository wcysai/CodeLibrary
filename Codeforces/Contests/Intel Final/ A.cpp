#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<snkueue>
using namespace std;
char str[10];
int a,b;
int main()
{
   scanf("%s",str);
  if(str[0]=='m') a=1;
    if(str[0]=='t'&&str[1]=='u') a=2;
    if(str[0]=='w') a=3;
    if(str[0]=='t'&&str[1]=='h') a=4;
    if(str[0]=='f') a=5;
    if(str[0]=='s'&&str[1]=='a') a=6;
    if(str[0]=='s'&&str[1]=='u') a=7;
   scanf("%s",str);
    if(str[0]=='m') b=1;
    if(str[0]=='t'&&str[1]=='u') b=2;
    if(str[0]=='w') b=3;
    if(str[0]=='t'&&str[1]=='h') b=4;
    if(str[0]=='f') b=5;
    if(str[0]=='s'&&str[1]=='a') b=6;
    if(str[0]=='s'&&str[1]=='u') b=7;
   if(b==a||b==a+3||b==a-4||b==a+2||b==a-5) printf("YES"); else printf("NO");
   return 0;
}

