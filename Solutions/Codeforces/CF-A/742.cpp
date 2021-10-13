#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  if(n == 0)
    cout << 1 << endl;
  else{
    n--;

    if(n % 4 == 0)
      cout << 8 << endl;

    if(n % 4 ==1)
      cout << 4 << endl;
    
    if(n % 4 == 2)
      cout << 2 << endl;

    if(n % 4 == 3)
      cout << 6 << endl;
  }
  



  
  return 0;
}