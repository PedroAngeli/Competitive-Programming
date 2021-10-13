#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  
  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet,vet+n);

  int menor = vet[0];
  int maior = vet[n-1];

  int dif = maior - menor;

  if(dif % 2 != 0){
    int cnt = 0;

    for(int i=0;i<n;i++){
      if(vet[i] == maior || vet[i] == menor)
        cnt++;  
    }

    if(cnt == n){
      cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
  }else{
    for(int k : {dif/2, dif}){
      int cnt = 0;
      for(int i=0;i<n;i++){
        if((vet[i] == maior || vet[i] == menor || vet[i] == menor + k)){
          cnt++;
        }
      }

      if(cnt == n){
        cout << "YES" << endl;
        return 0;
      }
    }

    cout << "NO" << endl;
  }

  return 0;
}