#include <bits/stdc++.h>

using namespace std;


int main(){

  long long n;
  
  while(cin >> n && n){
    long long r = sqrt(n);

    r * r == n ? cout << "yes\n" : cout << "no\n";
  }

  return 0;
}