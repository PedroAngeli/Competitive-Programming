#include <bits/stdc++.h>

using namespace std;

bool ok(int n){

  while(n > 0){
    if(n % 3 == 2)  return false;
    n = n/3;
  }

  return true;
}

int main(){

  int q;
  cin >> q;

  while(q--){
    int n;
    cin >> n;

    int ans = n;

    while(true){

      if(ok(ans))
        break;

      ans++;
    }

    cout << ans << endl;
  }

  return 0;
}