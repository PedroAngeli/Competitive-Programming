#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const double EPS = 1e-9;

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  double n;

  while(cin >> n){
    if(n < EPS)
      break;

    double a = (int)cbrt(n);
    double dx = (n-(a*a*a))/(3.0*a*a);

    cout << fixed << setprecision(4) << a + dx << endl;
  }
  
  
  return 0;
}