#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;
  bool vet[n+1] = {false};

  for(int i=0;i<n-1;i++){
    int temp;
    cin >> temp;
    vet[temp] = true;
  }

  for(int i=1;i<=n;i++){
    if(!vet[i]){
      cout << i << endl;
      break;
    }
  }


  return 0;
}