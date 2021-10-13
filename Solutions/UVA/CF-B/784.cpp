#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

vector <string> grid;

void solve(int i,int j){
  if(grid[i][j] != ' ')
    return;
  grid[i][j] = '#';
  solve(i+1,j);
  solve(i-1,j);
  solve(i,j+1);
  solve(i,j-1);
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  string lixo;
  getline(cin,lixo);
  while(t--){
    string line;
    string under;
    grid.clear();
    while(getline(cin,line)){
      if(line[0] == '_'){
        under = line;
        break;
      }
      grid.push_back(line);
    }
    int x,y;
    for(int i=0;i<grid.size();i++){
      for(int j=0;j<grid[i].size();j++)
        if(grid[i][j] == '*'){
          x = i, y = j;
          i = grid.size();
          break;
        }
    }
    grid[x][y] = ' ';
    solve(x,y);
    for(int i=0;i<grid.size();i++){
      for(char c:grid[i])
        cout << c;
      cout << endl;
    }
    cout << under << endl;
  }
  return 0;
}