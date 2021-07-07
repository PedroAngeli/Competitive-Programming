#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t;
  cin >> t;
  while(t--){
    long long a,b;
    cin >> a >> b;
    cout << (int)sqrt(b) - (int)sqrt(a-1) << endl;
  }
  
  return 0;
}