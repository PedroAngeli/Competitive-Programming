#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  if(n <= 5)
    cout << -1 << endl;
  else{
    for(int i=2;i<=n-2;i++)
      cout << 1 << " " << i << endl;
    cout << 2 << " " << n-1 << endl;
    cout << 2 << " " << n << endl;
  }

  for(int i=1;i<n;i++)
    cout << i << " " << i+1 << endl;
  
  return 0;
}