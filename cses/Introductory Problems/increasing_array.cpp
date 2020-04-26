#include <bits/stdc++.h>

using namespace std;


int main(){

 int n;
 cin >> n;
 long long vet[n];

 for(int i=0;i<n;i++)
  cin >> vet[i];

  long long resp = 0;

  for(int i=1;i<n;i++){
    if(vet[i] < vet[i-1]){
      resp += vet[i-1]-vet[i];
      vet[i] = vet[i-1];
    }
  }

  cout << resp << endl;

  return 0;
}