#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    long long n,k;
    cin >> n >> k;

    if(n>k)
      cout << k << endl;
    else{
        long long div = k/(n-1);
        long long qtd = n*div - div;
        if(k == qtd)
          qtd++;
        cout << n*div + (k-qtd) << endl;
    }
  }
    
  return 0;
}