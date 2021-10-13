#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n = 1;

  int x;
  cin >> x;

  if(x == 1){
    cout << 1 << endl;
    return 0;
  }
  
  while((n*n + 1)/2 < x){
    n+=2;
  }
  if(n == x)
    n+=2;
  cout << n << endl;
  
  return 0;
}