#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const double EPS = 1e-8;

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n,i;
    double p;
    cin >> n >> p >> i;
    double lose = 1.0 - p;
    if(lose == 1.0){
      cout << "0.0000" << endl;
      continue; 
    }
    double aux = lose;
    double ans = 0;
    int k = i-1;

    while(aux > EPS){
      ans += p*pow(lose,k);
      k+=n;
      aux = pow(lose,k);
    }
    ans += p*pow(lose,k);
    
    cout << fixed << setprecision(4) << ans << endl;
  }
  
  
  return 0;
}