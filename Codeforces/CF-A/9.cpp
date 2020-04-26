#include <bits/stdc++.h>

using namespace std;


int main(){

  int w,y;

  cin >> w >> y;

  int maior = max(w,y);

  int num = 6 - maior + 1;

  if(num == 0)
    cout << "0/1\n";
  else if(num == 6)
    cout << "1/1\n";
  else if(num == 3)
    cout << "1/2\n";
  else if(num % 2 == 0)
    cout << num/2 << "/" << 3 << endl;
  else 
    cout << num << "/" << 6 << endl;  
  return 0;
}