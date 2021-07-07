#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  
  int t;
  cin >> t;
  
  while(t--){
    int n;
    cin >> n;
    cout << max(0,n-2) << endl;
  }
  
  return 0;
}