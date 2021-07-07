#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int x,y,z;

bool solve(){
    for( int a : {x,y}){
      for( int b:{x,z}){
        for(int c:{y,z}){
          if(max(a,b) == x && max(a,c) == y && max(b,c) == z){
            cout << "YES" << endl;
            cout << a << " " << b << " " << c << endl;
            return true;
          }
        }
      }
    }
  return false;
}
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;

  while(t--){
    cin >> x >> y >> z;
    bool can = solve();

    if(!can)
      cout << "NO" << endl;  
  }
    
  return 0;
}