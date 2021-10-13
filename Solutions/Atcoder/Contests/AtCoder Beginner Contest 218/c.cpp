#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

const int nax = 200;
int n;

void print(vector <string>& grid){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout << grid[i][j];
    cout << endl;
  }
}

vector <string> rotate(vector <string>& grid){
  vector <string> new_grid(n, string(n, '.'));
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      new_grid[j][n-i-1] = grid[i][j];
  
  return new_grid;
}

bool valid(int i, int j){
  return i >= 0 and i < n and j >= 0 and j < n;
}

bool can(vector <string>& S, vector <string>& T){
  int si, sj;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(S[i][j] == '#'){
        si = i, sj = j, i = n;
        break;
      }
  int ti, tj;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(T[i][j] == '#'){
        ti = i, tj = j, i = n;
        break;
      }

  int di = si-ti;
  int dj = sj-tj;
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      if(S[i][j] == '.') continue;
      if(!valid(i-di, j-dj) or T[i-di][j-dj] == '.') 
        return false;
    }
  
  return true;
}

int main(){
  fastio;

  cin >> n;

  vector <string> S(n, string(n, '.'));
  vector <string> T(n, string(n, '.'));

  int cs = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> S[i][j], cs += (S[i][j] == '#');

  int ct = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> T[i][j], ct += (T[i][j] == '#');

  if(cs != ct){
    cout << "No" << endl;
    return 0;
  }

  for(int i=0;i<4;i++){

    if(can(S, T)){
      cout << "Yes" << endl;
      return 0;
    }

    S = rotate(S);
  }

  cout << "No" << endl;
  return 0;
}