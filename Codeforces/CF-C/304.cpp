#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if(n % 2 == 0)
    cout << -1 << endl;
  else{
    vector <int> a(n);
    vector <int> b(n);
    vector <int> c(n);
    for(int i=0;i<n;i++)
      a[i] = i, c[i] = n-i-1,b[i] = ((n+c[i]-a[i])%n);

    for(int i=0;i<n;i++)
      cout << a[i] << " ";
      cout << endl;
      for(int i=0;i<n;i++)
      cout << b[i] << " ";
      cout << endl;
        for(int i=0;i<n;i++)
      cout << c[i] << " ";
      cout << endl;
  }
  

  return 0;
}