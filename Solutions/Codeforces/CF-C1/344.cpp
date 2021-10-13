#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long a,b;

  cin >> a >> b;
  long long ans = 0;

  while(a != 0 && b != 0){
    if(a > b)
      ans += (a/b), a -= (a/b)*b;
    else 
      ans += (b/a), b -= (b/a)*a;
  }

  cout << ans << endl;

  return 0;
}