#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 
  int n,m;
  cin>> n >>m;

  vector <string> field(n);

  for(int i=0;i<n;i++)
    cin >> field[i];

  set <int> s;

  for(int i=0;i<n;i++){
    int p1,p2;
    for(int j=0;j<m;j++){
      if(field[i][j] == 'G')
        p1 = j;
      if(field[i][j] == 'S')
        p2 = j; 
    }

    if(p2 < p1){
      cout << -1 << endl;
      return 0;
    }

    s.insert(p2-p1);
  }

  cout << s.size() << endl;

  return 0;
}