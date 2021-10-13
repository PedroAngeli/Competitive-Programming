#include <bits/stdc++.h>

using namespace std;

bool cmp(int i,int j){
  return i > j;
}

int main(){

  int n,k;

  cin >> n >> k;
  vector <int> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet.begin(),vet.end(),cmp);

  int resp = k;
  int num = vet[k-1];

  for(int i=k;i<n;i++){
    if(vet[i] == num){
      resp++;
    }
      
    else
      break;
  }

  cout << resp << endl;
  return 0;
}