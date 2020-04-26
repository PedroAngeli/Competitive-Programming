#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;

  cin >> n;

  int vet[n];

  for(int i=0;i<n;i++){
    cin >> vet[i];
  }

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(vet[i] > vet[j]){
        int dif = vet[i] - vet[j];
        vet[j] += dif;
        vet[i] -= dif;
      } 
    }
  }

  for(int i=0;i<n;i++)
    cout << vet[i] << " ";

  cout << endl;


  return 0;
}