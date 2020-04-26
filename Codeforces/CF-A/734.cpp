#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;

  int a=0,d=0;

  for(int i=0;i<n;i++){
    char c;
    cin >> c;
    if(c=='A')
      a++;
    else 
      d++;
  }

  if(a == d)
    cout << "Friendship\n";
  else if(a > d)
    cout << "Anton\n";
  else
    cout << "Danik\n";
  

  return 0;
}