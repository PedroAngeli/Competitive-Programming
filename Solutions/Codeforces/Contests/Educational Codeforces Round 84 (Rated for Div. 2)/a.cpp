#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
 
  int t;
  cin >> t;
 
  while(t--){
    long long n, k;
 
    cin >> n >> k; 
 
    if(k % 2 == 0){
      if(n % 2 != 0)
        cout << "NO\n";
      else{
        long long v = ((1 + (k*2-1))*k)/2;
 
        if(v <= n)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
       
    }else{
      if(n % 2 == 0)
        cout << "NO\n";
      else{
        long long v = ((1 + (k*2-1))*k)/2;
 
        if(v <= n)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
  return 0;
}