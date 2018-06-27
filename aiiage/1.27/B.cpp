#include<bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define MAXN 9999
#define MAXSIZE 20
#define DLEN 4

class BigNum
{
private:
    int a[MAXN];    //可以控制大数的位数
    int len;       //大数长度
public:
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //构造函数
    BigNum(const int);       //将一个int类型的变量转化为大数
    BigNum(const char*);     //将一个字符串类型的变量转化为大数
    BigNum &operator=(const BigNum &);   //重载赋值运算符，大数之间进行赋值运算

    BigNum operator+(const BigNum &) const;   //重载加法运算符，两个大数之间的相加运算
    BigNum operator*(const BigNum &) const;   //重载乘法运算符，两个大数之间的相乘运算
    BigNum operator/(const int   &) const;    //重载除法运算符，大数对一个整数进行相除运算

    bool   operator>(const BigNum & T)const;   //大数和另一个大数的大小比较
    bool   operator==(const BigNum & T)const;   //大数和另一个大数的大小比较
    bool   operator>(const int & t)const;      //大数和一个int类型的变量的大小比较

};
BigNum::BigNum(const int b)     //将一个int类型的变量转化为大数
{
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const char*s)     //将一个字符串类型的变量转化为大数
{
    int t,k,index,l,i;
    memset(a,0,sizeof(a));
    l=strlen(s);
    len=l/DLEN;
    if(l%DLEN)
        len++;
    index=0;
    for(i=l-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}

BigNum & BigNum::operator=(const BigNum & n)   //重载赋值运算符，大数之间进行赋值运算
{
    int i;
    len = n.len;
    memset(a,0,sizeof(a));
    for(i = 0 ; i < len ; i++)
        a[i] = n.a[i];
    return *this;
}

BigNum BigNum::operator+(const BigNum & T) const   //两个大数之间的相加运算
{
    BigNum t(*this);
    int i,big;      //位数
    big = T.len > len ? T.len : len;
    for(i = 0 ; i < big ; i++)
    {
        t.a[i] +=T.a[i];
        if(t.a[i] > MAXN)
        {
            t.a[i + 1]++;
            t.a[i] -=MAXN+1;
        }
    }
    if(t.a[big] != 0)
        t.len = big + 1;
    else
        t.len = big;
    return t;
}

BigNum BigNum::operator*(const BigNum & T) const   //两个大数之间的相乘运算
{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i = 0 ; i < len ; i++)
    {
        up = 0;
        for(j = 0 ; j < T.len ; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i + j] + up;
            if(temp > MAXN)
            {
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = temp1;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
bool BigNum::operator>(const BigNum & T) const   //大数和另一个大数的大小比较
{
    int ln;
    if(len > T.len)
        return true;
    else if(len == T.len)
    {
        ln = len - 1;
        while(a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if(ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
bool BigNum::operator==(const BigNum & T) const   //大数和另一个大数的大小比较
{
    int ln;
    if(len != T.len)
        return false;
    else 
    {
        ln = len - 1;
        while(a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if(ln==-1)
            return true;
        else
            return false;
    }
}
bool BigNum::operator >(const int & t) const    //大数和一个int类型的变量的大小比较
{
    BigNum b(t);
    return *this>b;
}

BigNum save[16];
int main()
{
    int t;
    scanf("%d",&t);
    char str[MAXN];
    save[0]=BigNum(2);
    BigNum res=BigNum(2);
    for(int i=1;i<=15;i++)
    {
        res=res*res;
        save[i]=res;
    }
    for(int i=0;i<t;i++)
    {
        scanf("%s",str);
        if(str[0]=='-'||str[0]=='0')
        {
            puts("No");
            continue;
        }
        if(strlen(str)>=5000)
        {
            printf("No");
        }
        if(strlen(str)==1)
        {
            if(str[0]=='1'||str[0]=='2'||str[0]=='4'||str[0]=='8')
            {
                puts("Yes");
                continue;
            }
            else 
            {
                puts("No");
                continue;
            }
        }
        BigNum n=BigNum(str);
        int k=0;
        while(n>save[k]) k++;
        BigNum ll=save[k-1],rr=save[k];
        bool f=false;
        if(n==save[k])
        {
            puts("Yes");
            continue;
        }
        int mult=k-2;
        while(rr>ll+BigNum(1))
        {
            if(mult==-1)
            {
                if(ll==n||rr==n) f=true;
                break;
            }
            BigNum now=ll*save[mult];
            if(now==n)
            {
                f=true;
                break;
            }
            if(n>now) ll=now; else rr=now;
            mult--;
        }
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}

