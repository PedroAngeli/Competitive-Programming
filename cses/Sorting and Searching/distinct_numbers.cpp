#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  set<int> conj;

  while (n--){
    int a;
    cin >> a;
    conj.insert(a);
  }

  cout << conj.size() << endl;

  return 0;
}