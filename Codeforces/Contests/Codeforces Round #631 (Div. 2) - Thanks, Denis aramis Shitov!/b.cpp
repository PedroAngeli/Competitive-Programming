#include <bits/stdc++.h>

using namespace std;

int idx;
int n;
set <int> s;
 vector <int> vet;

bool isPossible(int p){
  s.clear();
  
  for(;idx<n;idx++){
    if(vet[idx] <= p){
        if(s.count(vet[idx])){
          return false;
        }else{
          s.insert(vet[idx]);
        }
      }
      else{
        return false;
      }

      if(s.size() == p){
        return true;
      }
  }
}

int main(){

  int t;
  cin >> t;

  while(t--){
    cin >> n;
    int m = 0;
   
    vet.resize(n);

    for(int i=0;i<n;i++){
      cin >> vet[i];
      m = max(m,vet[i]);
    }

    int p1 = m;
    int p2 = n-m;

    idx = 0;
    if(isPossible(p1) && ++idx && isPossible(p2)){
      idx = 0;
      if(p1 != p2 && isPossible(p2) && ++idx && isPossible(p1)){
        cout << "2\n";
        cout << p1 << " " << p2 << endl;
        cout << p2 << " " << p1 << endl;
      }else{
        cout << "1\n";
        cout << p1 << " " << p2 << endl;
      }
      continue;
    }

    idx = 0;

    if(isPossible(p2) && ++idx && isPossible(p1)){
      cout << "1\n";
      cout << p2 << " " << p1 << endl;
    }else{
      cout << "0\n";
    }
  }
  return 0;
}