#include <bits/stdc++.h>

using namespace std;


int main(){

  int a,b;

  cin >> a >> b;
  
  int resp = 0;
  while(a <= b){
    resp++;
    a*=3;
    b*=2;
  }

  cout << resp << endl;
  return 0;
}