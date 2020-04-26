#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;

long long binary_pow(long long a, long long b){
  a = a%m;
  long long ans = 1;

  while(b>0){
    if(b & 1){
      ans = (ans * a) % m;
    }

    a = (a * a)%m;
    b = b >> 1;
  }

  return ans;
}

int main(){

  int n;
  cin >> n;

  cout << binary_pow(2,n) << endl;
  
  return 0;
}