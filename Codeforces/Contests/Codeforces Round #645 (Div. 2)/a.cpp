#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int t = 1;
  cin >> t;

  while(t--){
    int n,m;
    cin >> n >> m;
    if(m % 2 == 0)
      cout << m/2 * n << endl;
    else if(n % 2 == 0)
      cout << m/2 * n + n/2 << endl;
    else
      cout << m/2 * n + n/2 + 1 << endl;
  }

  return 0;
}