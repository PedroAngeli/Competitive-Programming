#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  
  map <char,int> mapa;

  mapa['A'] = 0;
  mapa['B'] = 0;
  mapa['C'] = 0;

  string s;

  while(cin >> s){
    char c1 = s[0];
    char c2 = s[2];
    char op = s[1];

    if(op == '>')
      mapa[c1]++,mapa[c2]--;
    else
      mapa[c2]++,mapa[c1]--;
  }

  if(mapa['A'] == 0 && mapa['B'] == 0 && mapa['C'] == 0)
    cout << "Impossible" << endl;
  else{
    vector <pair<int,char> > ans;
    ans.push_back({mapa['A'],'A'});
    ans.push_back({mapa['B'],'B'});
    ans.push_back({mapa['C'],'C'});
    sort(ans.begin(),ans.end());

    for(int i=0;i<3;i++)
      cout << ans[i].second;
    cout << endl;
  }


  return 0;
}