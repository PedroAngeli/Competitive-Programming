#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  map <string, int> gols;

  while(n--){
    string s;
    cin >> s;
    
    if(!gols.count(s))
      gols[s] = 1;
    else
      gols[s]++;
  }

  auto it = gols.begin();

  if(gols.size() > 1){
      auto itemp = gols.begin();
      auto it1 = ++itemp;

    if(it1 != gols.end()){
      if(it->second > it1->second)
        cout << it->first << endl;
      else
        cout << it1->first << endl;
    }
  }
  else{
    cout << it->first << endl;
  }
  return 0;
}