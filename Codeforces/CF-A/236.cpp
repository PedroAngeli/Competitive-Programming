#include <bits/stdc++.h>

using namespace std;


int main(){

 
  char c;
  set <char> s;

  while(cin >> c){
    s.insert(c);
  }

  if(s.size() % 2 == 0)
    cout << "CHAT WITH HER!\n";
  else
    cout << "IGNORE HIM!\n";


  return 0;
}