#include <bits/stdc++.h>

using namespace std;

const int nax = 1e6 + 5;
int c[nax];

int main(){

  int n;

  cin >> n;

  vector <int> vet(n);
  int maior = 0;

  for(int i=0;i<n;i++){
    cin >> vet[i];
    maior = max(maior,vet[i]);
  }

  for(int i=0;i<n;i++){
    for(int j=1;j*j<=vet[i];j++){
      if(vet[i] % j == 0){
        c[j]++;

        if(j != vet[i]/j){
          c[vet[i]/j]++;
        }
      }
    }
  }

  for(int i=maior;i>=1;i--){
    if(c[i] > 1){
      cout << i << endl;
      break;
    }
  }
    

  

  return 0;
}