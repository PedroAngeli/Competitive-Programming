#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t, k, d;
  cin >>  n>> t >> k >> d;

  if (((d / t) + 1) * k >= n) cout << "NO" << endl;
  else cout << "YES" << endl;
  
  return 0;
}