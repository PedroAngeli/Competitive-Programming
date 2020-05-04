#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int mod = 1e9 + 7;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int x,y,n;
  cin >> x >> y >> n;

  int f[3];
  f[0] = y-x;
  f[1] = x;
  f[2] = y;


  int q = n/3;
  int r = n%3;

  if(r == 0)
    q--;

  int ans;

  if(q % 2 == 0)
    ans = f[r];
  else
    ans = -f[r];

  cout << ((ans%mod)+mod)%mod << endl;



  return 0;
}