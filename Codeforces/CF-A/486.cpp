#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;

  cin >> n;

  if(n % 2 == 0)
    cout << n/2 << endl;
  else
    cout << (-2*n-1)/4 - 1 << endl;


  
  return 0;
}