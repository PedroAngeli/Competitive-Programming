#include <bits/stdc++.h>

using namespace std;


int main(){

  string a;
  cin >> a;

  int count = 1;
  int resp = 1;

  for(int i=0;i<a.size()-1;i++){
    if(a[i] == a[i+1])
      count++;
    else 
      count = 1;

    resp = max(resp, count);
  }

  cout << resp << endl;


  return 0;
}