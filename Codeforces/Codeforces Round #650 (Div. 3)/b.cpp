#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int vet[n];
    for(int i=0;i<n;i++)
      cin >> vet[i];

    int even = 0;
    int odd =0;
    int out = 0;

    for(int i=0;i<n;i++){
      if(vet[i] % 2 == 0)
        even++;
      else
        odd++;

      if(i%2 != vet[i]%2)
        out++;
    }

    if(even != (n+1)/2)
      cout << -1 << endl;
    else
      cout << out/2 << endl;
  }

  return 0;
}