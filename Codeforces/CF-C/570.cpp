#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int mod = 1e9 + 7;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int m,n;
  cin >> n >> m;

  if(n == 1)
    cout << 1 << endl;
  else if(n-m > m-1)
    cout << m+1 << endl;
  else 
    cout << m-1 << endl;


  return 0;
}