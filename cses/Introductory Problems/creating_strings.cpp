#include <bits/stdc++.h>

using namespace std;


int main(){

  string a;
  cin >> a;
  vector <string> vet;
  sort(a.begin(),a.end());
  vet.push_back(a);
  while(next_permutation(a.begin(),a.end())){
    vet.push_back(a);
  }

  cout << vet.size() << endl;
  
  for(int i=0;i<vet.size();i++)
    cout << vet[i] << endl;

  return 0;
}