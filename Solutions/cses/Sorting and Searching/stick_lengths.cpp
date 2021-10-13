#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;
  vector <int> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet.begin(),vet.end());

  int idx = (n-1)/2;
  int num = vet[idx];
  long long resp = 0;

  for(int i=0;i<n;i++){
    resp += abs(vet[i] - num);
  }

  cout << resp << endl;

 

  return 0;
}