#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
char c;
vector <string> office;
set <char> ans;

bool valid(int i,int j){
    return i >=0 && i < n && j >=0 && j < m && office[i][j] != '.';
}

void solve(int i, int j){

  ans.insert(office[i][j]);

  if(valid(i+1,j))
    ans.insert(office[i+1][j]);

  if(valid(i-1,j))
    ans.insert(office[i-1][j]);

  if(valid(i,j-1))
    ans.insert(office[i][j-1]);

  if(valid(i,j+1))
    ans.insert(office[i][j+1]);
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> c;
  office.resize(n);

  for(int i=0;i<n;i++)
    cin >> office[i];

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(office[i][j] == c){
        solve(i,j);
      }
    }
  }
    
  cout << ans.size()-1 << endl;
  
  return 0;
}