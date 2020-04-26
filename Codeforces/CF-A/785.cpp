#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map <string,int> poly;
  poly["Tetrahedron"] = 4;
  poly["Cube"] = 6;
  poly["Octahedron"] = 8;
  poly["Dodecahedron"] = 12;
  poly["Icosahedron"] = 20;

  int n;
  cin >> n;

  long long ans = 0;

  while(n--){
    string s;
    cin >> s;
    ans += poly[s];
  }

  cout << ans << endl;
  return 0;
}