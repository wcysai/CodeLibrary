#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int main()
{
    double beta=0.0;
    for(int i=0;i<100;i++)
    {
        double x=(1-beta)*(1-beta)/4/(1+beta);
        double res=(1-beta)/4-exp(-x);
        printf("%.10f %.10f\n",beta,res);
        beta+=0.01;
    }
}