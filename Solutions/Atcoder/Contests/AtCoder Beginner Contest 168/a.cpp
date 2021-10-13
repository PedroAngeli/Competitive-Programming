#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

 
  int n;
  cin >> n;

  int dig = n%10;

  if(dig == 3)
    cout << "bon" << endl;
  else if(dig == 0 || dig == 1 || dig == 6 || dig == 8)
  cout << "pon" << endl;
  else
    cout << "hon" << endl;

  return 0;
}