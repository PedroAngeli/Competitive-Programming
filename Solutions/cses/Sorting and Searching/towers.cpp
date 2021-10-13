#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;
  vector <int> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  multiset <int> top;

  for(int i=0;i<n;i++){
    auto it = top.upper_bound(vet[i]);

    if(it == top.end()){
      top.insert(vet[i]);
    }else{
      top.erase(it);
      top.insert(vet[i]);
    }
  }

  cout << (int)top.size() << endl;

 

  return 0;
}