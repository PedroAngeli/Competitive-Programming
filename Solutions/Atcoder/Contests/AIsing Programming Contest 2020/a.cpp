#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int l,r,d;

  cin >> l >> r >> d;

  l--;

  cout << (r/d) - (l/d) << endl;

  return 0;
}