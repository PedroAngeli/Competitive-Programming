#include <bits/stdc++.h>


using namespace std;


int main(){

  int n;

  while(cin >> n){
    if(n % 100 == 0)
      cout << n/100 << endl;
    else
      cout << n/100 + 1 << endl;
  }

  return 0;
}