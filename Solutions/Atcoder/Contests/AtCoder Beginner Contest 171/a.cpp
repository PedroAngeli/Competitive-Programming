#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  cin >> c;

  if(c >= 'A' && c <= 'Z')
    cout << "A" << endl;
  else
    cout << "a" << endl;
 
  return 0;
}