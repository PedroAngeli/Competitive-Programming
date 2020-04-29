#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int a,b;

  while(cin >> a >> b){
    int ans = 0;

    for(int i=0;i<32;i++){
      if((a & (1 << i)) && !(b & (1 << i))  || !(a & (1 << i)) && (b & (1 << i)))
        ans += (1 << i);
    }

    cout << ans << endl;
  }
  
  return 0;
}