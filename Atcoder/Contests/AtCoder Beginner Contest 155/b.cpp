#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  bool can = true;

  while(n--){
    int a;
    cin >> a;

    if(a % 2 == 0){
      if(!(a%3 == 0 || a%5 == 0)){
        can = false;
      }
    }
  }
  
  if(can){
     cout << "APPROVED\n";
  }else{
     cout << "DENIED\n";
  }
 

  return 0;
}