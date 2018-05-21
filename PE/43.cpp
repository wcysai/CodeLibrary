#include<iostream>  
#include<algorithm>  
using namespace std;  
  
int digit[10]={0,1,2,3,4,5,6,7,8,9};  
  
bool check()  
{  
    if(digit[0]==0) return false;  
    if(digit[3]&1)return false;  
    if((digit[4]+digit[3]+digit[2])%3) return false;  
    if(digit[5]%5) return false;  
    if((digit[4]*100+digit[5]*10+digit[6])%7) return false;  
    if((digit[5]*100+digit[6]*10+digit[7])%11) return false;  
    if((digit[6]*100+digit[7]*10+digit[8])%13) return false;  
    if((digit[7]*100+digit[8]*10+digit[9])%17) return false;  
    return true;  
}  
  
int main()  
{  
    long long ans=0;  
    for(int i=0;i<3628800;i++)  
    {  
        next_permutation(digit,digit+10);  
        if(check())  
        {  
            long long tmp=0;  
            for(int i=0;i<10;i++)  
            {  
                 cout<<digit[i];  
                 tmp=tmp*10+digit[i];  
            }  
            cout<<endl;  
            ans+=tmp;  
        }  
    }  
    cout<<ans<<endl;  
  
}  