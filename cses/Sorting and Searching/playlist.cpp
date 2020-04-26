#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;
  vector <int> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  set <int> ids;
  int resp = 0;
  int j = 0, i;

  for(i=0;i<n;i++){
    if(ids.count(vet[i])){
      resp = max(resp,i-j);

      while(vet[i] != vet[j]){
        ids.erase(vet[j]);
        j++;
      }
      j++;
    }else{
      ids.insert(vet[i]);
    }
  }

  resp = max(resp,i-j);

  cout << resp << endl;
 

  return 0;
}