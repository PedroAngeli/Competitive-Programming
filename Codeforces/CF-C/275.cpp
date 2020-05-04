#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;

  cin >> n >> k;

  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet,vet+n);

  set <int> s;

  for(int i=0;i<n;i++){
    if(vet[i] % k == 0){
      if(!s.count(vet[i]/k))
        s.insert(vet[i]);
    }else
      s.insert(vet[i]);
  } 

  cout << s.size() << endl;

  return 0;
}