#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int ini = 0;
  int ans = 0;

  while(true){
    int pos = s.find("bear",ini,4);
    if(pos == string :: npos)
      break;

      int dif = pos - ini;
      int tam = s.size();
      int posr = pos + 3;
      ans += (dif*(tam-posr));
      ans += (tam - posr);

    ini = pos + 1;
  }

  cout << ans << endl;
  return 0;
}