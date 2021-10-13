#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k;

  cin >> n >> k;
  n = 2*n + 1;

  ll vet[n];

  for(int i=0;i<n;i++){
    cin >> vet[i];
  }

  bool checked[n];
  memset(checked,false,sizeof checked);

  for(int j=0;j<k;j++){
    ll maior = 0;
    ll idx = 0;

    for(int i=1;i<n-1;i++){
      if(vet[i] > maior && (vet[i]-1) > vet[i-1] && (vet[i]-1) > vet[i+1] && !checked[i]){
        maior = vet[i];
        idx = i;
      }
    }

    checked[idx] = true;
    vet[idx]--;
  }

  for(int i = 0;i<n;i++)
    cout << vet[i] << " ";

  cout << endl; 

  
   

  return 0;
}