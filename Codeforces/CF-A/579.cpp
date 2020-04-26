#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[1001];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x;

  cin >> x;
  int ans = 0;

  while(x > 0){
    if(x & 1)
      ans++;

    x = x >> 1;
  }

  cout << ans << endl;
  return 0;
}