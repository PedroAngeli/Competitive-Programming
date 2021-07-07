#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    long long a,b,c;
    cin >> a >> b >> c;

    if(a < c)
      cout << 1 << " ";
    else 
      cout << -1 << " ";
    
    if(c < a*b)
      cout << b << endl;
    else
      cout << -1 << endl;
  }
  
   
  return 0;
}