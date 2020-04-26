#include <bits/stdc++.h>

using namespace std;


int main(){

 int k, r;

 cin >> k >> r;
  int ans = 1;
  int temp = k;
  while(temp%10 != 0 && temp%10 != r){
    ans++;
    temp += k;
  }

  cout << ans << endl;
  return 0;
}