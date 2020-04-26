#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;

  cin >> n >> k;

  long long value = 0;

  while(n--){
    int l,r;
    cin >> l >> r;
    value += r-l+1;
  }

  if(value % k == 0)
    cout << 0 << endl;
  else
    cout << k - (value % k) << endl;

  return 0;
}