#include <bits/stdc++.h>

using namespace std;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double p;
  while(cin >> n >> p){
    cout << fixed << setprecision(0) << pow(2,log2(p)/n) << endl;
  }

  return 0;
}