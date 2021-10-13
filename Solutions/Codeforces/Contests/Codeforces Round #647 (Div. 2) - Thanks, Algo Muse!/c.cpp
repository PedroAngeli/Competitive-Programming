#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

    int cnt[120];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  
  while(t--){
    long long n;
    cin >> n;
    long long ans = 0;
    long long cnt = 1;
    while(n){
      ans += cnt*(n/2 + n%2);
      n/=2;
      cnt++;
    }
    cout << ans << endl;
  }

  return 0;
}