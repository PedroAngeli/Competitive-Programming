#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    if(n % 4 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  

  return 0;
}