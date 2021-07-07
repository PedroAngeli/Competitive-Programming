#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  map <int,long long> mapa;

  for(int i=1;i<=n;i++){
    int b;
    cin >> b; 
    mapa[i-b] += b;
  }

  map <int,long long> :: iterator it;

  long long ans = 0;

  for(it = mapa.begin();it != mapa.end();it++){
    ans = max(ans, it->second);
  }

  cout << ans << endl;
}