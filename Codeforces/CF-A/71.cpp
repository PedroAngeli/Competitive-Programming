#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  while(n--){
    string s;
    cin >> s;

    int tam = s.size();

    if(tam > 10){
      cout << s[0] << tam-2 << s[tam-1] << endl;
    }
    else
      cout << s << endl;
  }
  
  return 0;
}