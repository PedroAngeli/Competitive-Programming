#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t = 1;
  cin >> t;
  while(t--){
    long long x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (x2-x1)*(y2-y1) + 1 << endl;
  }
  
  return 0;
}