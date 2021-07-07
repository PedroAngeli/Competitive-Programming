#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main(){

  int t,n;

    cin >> n;

    vector <long long> b(n);
    vector <long long> a(n);

    for(long long i=0;i<n;i++)
      cin >> b[i];

  a[0] = b[0];

  long long maior = -INF;

  for(long long i=1;i<n;i++){
    maior = max(maior,a[i-1]);
    a[i] = b[i] + maior;
  }

  for(long long i=0;i<n;i++)
      cout << a[i] << " ";

  cout << endl;


  return 0;
}