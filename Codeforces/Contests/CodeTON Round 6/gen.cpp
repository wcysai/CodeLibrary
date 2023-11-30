#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << "1\n";
  cout << "5000\n";
  for (int i = 0; i < 5000; i++) {
      if(i){cout << " ";}
      int oup=i%2048;
      cout << oup;
  }cout << "\n";
  return 0;
}
