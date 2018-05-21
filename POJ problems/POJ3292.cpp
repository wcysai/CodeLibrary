#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 250001
using namespace std;
int hnumber[MAXN],primeh[MAXN],semih[MAXN];
bool is_primeh[MAXN];
int main()
{
    for(int i=0;i<MAXN;i++) hnumber[i]=4*i+1;
    for(int i=0;i<MAXN;i++) is_primeh[i]=true;
    int p=0;
    is_primeh[0]=false;
    for(int i=1;i<MAXN;i++)
        if(is_primeh[i])
    {
        primeh[++p]=hnumber[i];
        for(int j=5*hnumber[i];j<=4*MAXN;j+=4*hnumber[i])
            is_primeh[(j-1)/4]=false;
    }
    int i=1,k=0;
    while(i*i<4*MAXN)
    {
        for(int j=i;primeh[i]*primeh[j]<4*MAXN;j++)
        {
            semih[k]=primeh[i]*primeh[j];
            k++;
        }
        i++;
    }
    sort(semih,semih+k);
    int x;
    scanf("%d",&x);
    while(x!=0)
    {
        int h=0;
        for(int i=0;i<=k;i++)
        {
            if(semih[i]>x) break;
            if(i==0||semih[i]!=semih[i-1]) h++;
        }
        printf("%d %d\n",x,h);
        scanf("%d",&x);
    }
    return 0;
}