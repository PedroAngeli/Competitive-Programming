#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    string x;
    cin >> x;

    string a,b;
    a.resize(n);
    b.resize(n);
    bool one = false;

    for(int i=0;i<n;i++){
      if(x[i] == '0'){
        a[i] = '0', b[i] = '0';
      }else if(x[i] == '1'){
        if(one)
          a[i] = '0', b[i] = '1';
        else
          a[i] = '1', b[i] = '0';
          
        one = true;
      }else{
        if(one){
          a[i] = '0';
          b[i] = '2';
        }else{
          a[i] = '1', b[i] = '1';
        }
      }
    }
    
    cout << a << "\n" << b << "\n";
  }

  return 0;
}