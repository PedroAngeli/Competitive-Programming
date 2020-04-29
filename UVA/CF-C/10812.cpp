#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int a,b;
    cin >> a >> b;

    int mx = (a+b)/2;
    int mn = a - mx;

    if(mn < 0 || (a+b)%2 == 1)
      cout << "impossible" << endl;
    else
      cout << mx << " " << mn << endl;
  }
  
  
  return 0;
}