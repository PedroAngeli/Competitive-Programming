#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int k = (n+999)/1000;

  cout << k*1000-n << endl;
 
  return 0;
}