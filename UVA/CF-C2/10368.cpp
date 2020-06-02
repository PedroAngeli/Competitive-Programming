#include <bits/stdc++.h>

using namespace std;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int a,b;
  while(cin >> a >> b && a && b){
    bool turn = true;
    while(a && b){
      if(a > b)
        swap(a,b);
      if(b/a >= 2 || b%a == 0)
        break;
      b = b%a;
      turn = !turn;
    }

    if(turn)
      cout << "Stan wins" << endl;
    else
      cout << "Ollie wins" << endl;
  }

 

  return 0;
}