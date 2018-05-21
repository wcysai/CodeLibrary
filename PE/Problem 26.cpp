#include<bits/stdc++.h>
using namespace std;  
int abc(int i)  
{  
    int n=0,m=0;  
    while(i%2==0) i/=2;  
    while(i%5==0) i/=5;  
    if(i==1) return 0;  
    while(1)  
    {  
        m++;  
        n=(n*10+9)%i;  
        if(n==0) break;  
    }  
    return m;  
}  
int main()  
{  
    int n=0,m;  
    for(int i=2;i<=1000;i++)  
    {  
        int l=abc(i);  
        if(l>n) {n=l;m=i;}  
    }  
    cout<<m<<endl;  
    return 0;  
}  