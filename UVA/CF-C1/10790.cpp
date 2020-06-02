#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long a,b;
  int ncase = 1;
  while(cin >> a >> b && a){
      
    long long ans = (a*(a-1)/2)*(b*(b-1)/2);
    cout << "Case " << ncase++ << ": " << ans << endl;
  }
  
  return 0;
}