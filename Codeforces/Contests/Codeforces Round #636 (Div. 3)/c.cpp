#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    long long vet[n];

    for(int i=0;i<n;i++)
      cin >> vet[i];

    long long ans = 0;
    const long long INF = 1e9+7;
    long long maior = -INF;

    for(int i=0;i<n-1;i++){
      maior = max(vet[i],maior);
      if(vet[i+1] < 0 && vet[i] > 0 || vet[i] < 0 && vet[i+1] > 0){
        ans += maior;
        maior = -INF;
      }
    }

    maior = max(maior,vet[n-1]);

    ans += maior;

    cout << ans << endl;
  }
  

  return 0;
}