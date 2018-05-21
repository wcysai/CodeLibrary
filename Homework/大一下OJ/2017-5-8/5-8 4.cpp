#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
void f2(string &pre,string in, string post)
 {
    if(post.length()==0)
        return;
    int n=post.length()-1;
    char ch=post[n];
    pre+=ch;
    f2(pre,in.substr(0,in.find(ch)),post.substr(0,in.find(ch)));
     f2(pre,in.substr(in.find(ch)+1,in.length()-in.find(ch)-1),post.substr(in.find(ch),in.length()-in.find(ch)-1));

 }
int main()
 {
     string pre="";
     string in,post;
     cin>>in;
     cin>>post;
     f2(pre,in,post);
     cout<<pre<<endl;
     return 0;
 }
