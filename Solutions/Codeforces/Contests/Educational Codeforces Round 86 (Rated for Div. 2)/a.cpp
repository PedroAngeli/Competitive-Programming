#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  int t;
  cin >> t;

  while(t--){
    long long x,y;
    long long a,b;
    cin >> x >> y;
    cin >> a >> b;

    if(x < y)
      swap(x,y);
    
    long long dif = x-y;
    long long ans = min(b*y + dif*a, x*a + y*a);

    cout << ans << endl;

  }
  return 0;
}