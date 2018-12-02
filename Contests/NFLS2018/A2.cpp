#include <stdio.h>
int main()
{
  int n;
  char c;
  FILE *f;
  f=fopen(__FILE__,"r");
  scanf("%d",&n);
 while(n--)
 {
 while((c=getc(f))!=EOF)
 putchar(c);
 fseek(f,0,0);
 }
  return 0;
} 
