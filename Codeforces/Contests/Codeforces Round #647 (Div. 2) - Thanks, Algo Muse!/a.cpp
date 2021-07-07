#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  
  while(t--){
    long long a,b;
    cin >> a >> b;
    if(a > b)
      swap(a,b);

    long long cnt = 0;
    while(a < b)
      a*=2,cnt++;

    if(a == b){
      long long ans = 0;
      ans = cnt/3;
      cnt = cnt%3;
      ans += cnt/2;
      cnt = cnt%2;
      ans += cnt;
      cout << ans << endl;
    }
    else
      cout << -1 << endl;
  }

  return 0;
}