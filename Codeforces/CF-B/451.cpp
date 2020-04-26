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

  int i = 0;

  int l = 0;
  int r = 0;
  bool flag = true;

  for(int i=0;i<n-1;i++){
    if(vet[i] > vet[i+1]){
      flag = false;
      l = i;
      while(i < n-1 && vet[i] > vet[i+1]){
        i++;
      }
      r = i;
      break;
    }
  }

  if(flag){
    cout << "yes" << endl << "1 1" << endl;
    return 0;
  }

  reverse(vet+l,vet+r+1);

  for(int i=0;i<n-1;i++){
    if(vet[i] > vet[i+1]){
      cout << "no" << endl;
      return 0;
    }
  }

  cout << "yes" << endl << l+1 << " " << r+1 << endl;
  
  return 0;
}