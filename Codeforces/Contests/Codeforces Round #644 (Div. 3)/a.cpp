#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int a,b;
    cin >> a >> b;
    if(a > b){
      swap(a,b);
    }
    if(a+a >= b)
      cout << (a+a)*(a+a) << endl;
    else
      cout << b*b << endl;
  }

  return 0;
}