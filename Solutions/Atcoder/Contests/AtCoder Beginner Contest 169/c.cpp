#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long a;
  long double b;
  cin >> a >> b;
  long long ans = a*b*100;
  cout << ans/100 << endl;
  return 0;
}