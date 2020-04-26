#include <bits/stdc++.h>

using namespace std;

int main(){

  long long n;
  cin >> n;

  long long pot = 1;
  long long resp = 0;
  int exp = 1;

  while(pot <= n){
    pot = pow(5,exp++);
    resp += n/pot;
  }

  cout << resp << endl;

  return 0;
}