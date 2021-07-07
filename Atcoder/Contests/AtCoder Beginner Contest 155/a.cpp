#include <bits/stdc++.h>

using namespace std;

int main(){

  int a,b,c;

  cin >> a >> b >> c;

  if(a == b && a != c)
    cout << "Yes\n";
  else if(a == c && a != b)
    cout << "Yes\n";
  else if(b == c && b != a)
    cout << "Yes\n";
  else 
    cout << "No\n";
  

  return 0;
}