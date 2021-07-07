#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;

  while(cin >> n){
    if(n==-1)
      break;

    int b = n % 257;
    int c = n % 193;
    int delta = b*b - 4*c;

    if(delta < b*b){
      cout << "So o ouro\n";
    }else if((delta == 0 && b == 0) || b*b == delta){
      cout << "Bom\n";
    }else{
      cout << "Regular\n";
    }
  }


  return 0;
}