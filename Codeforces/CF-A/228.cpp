#include <bits/stdc++.h>

using namespace std;


int main(){

  int s1,s2,s3,s4;

  cin >> s1 >> s2 >> s3 >> s4;

  set <int> conj;

  conj.insert(s1);
  conj.insert(s2);
  conj.insert(s3);
  conj.insert(s4);

  cout << 4 - conj.size() << endl;
  return 0;
}