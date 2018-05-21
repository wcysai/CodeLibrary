#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 105
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
  
int compute(int a)  
{  
    return a*(3 * a - 1) / 2;  
}  
  
bool ok(int a)  
{  
    for (int i = 1; i*(3*i-1) <= 2*a; i++)  
    {  
        if (i*(3 * i - 1) == 2 * a)  
            return true;  
    }  
    return false;  
}  
  
  
int main()  
{  
    for (int i = 2; i <= 3000; i++)  
    {  
        for (int j = 1; j < i; j++)  
        {  
            int plus = compute(i) + compute(j);  
            int diff = compute(i) - compute(j);  
            if (ok(plus) && ok(diff))  
                cout << diff << endl;  
        }  
    }  
    return 0;  
}  

