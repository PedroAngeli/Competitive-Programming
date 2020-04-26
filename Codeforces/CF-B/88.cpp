#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int dist(int x1,int y1,int x2,int y2){
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int mat[256][256];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 
  int n,m;
  int x;

  cin >> n >> m >> x;

  vector <string> keyboard(n);
  vector <vector<pair<int,int> > > pos(256);
  vector <bool> exists(256,false);

  for(int i=0;i<n;i++){
    cin >> keyboard[i];
    for(int j=0;j<m;j++){
      exists[keyboard[i][j]] = true;
      pos[keyboard[i][j]].push_back({i,j});
    }
  }

  for(int i=0;i<256;i++)
    for(int j=0;j<256;j++)
      mat[i][j] = 1e9+7;

  for(int i=0;i<=255;i++){
    for(int j=0;j<pos[i].size();j++){
      for(int k=0;k<=255;k++){
        for(int l=0;l<pos[k].size();l++){
          int x1 = pos[i][j].first;
          int y1 = pos[i][j].second;
          int x2 = pos[k][l].first;
          int y2 = pos[k][l].second;

          mat[i][k] = min(mat[i][k], dist(x1,y1,x2,y2));
        }
      }
    }
  }

  int q;
  cin >> q;
  string text;

  cin >> text;
  int ans = 0;

  for(int i=0;i<q;i++){
    if(text[i] >= 'A' && text[i] <= 'Z'){
      if(exists['S'] == 0 || exists[text[i]-'A'+'a'] == 0){
        cout << -1 << endl;
        return 0;
      }

      text[i] = text[i] - 'A' + 'a';
      
      if(mat[text[i]]['S'] > x*x)
        ans++;

    }else{
      if(exists[text[i]] == 0){
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << ans << endl;


  return 0;
}