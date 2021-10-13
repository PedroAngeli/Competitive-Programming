#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;

  while(cin >> n && n){
    int vet[2*n];

    for(int i=0;i<2*n;i++)
      cin >> vet[i];

    int maior = 0;
    int menor = 1e9 + 7;

    for(int i=0,j=2*n-1;i < j;i++,j--){
      int sum = vet[i] + vet[j];
      
      if(sum > maior)
        maior = sum;
      
      if(sum < menor)
        menor = sum;
    }

    cout << maior << " " << menor << endl;
  }

  return 0;
}