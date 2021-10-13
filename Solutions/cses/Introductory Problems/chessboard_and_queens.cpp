#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

bool can_place[8][8];
int placed[8];

int solve(int column){
  if(column == 8) return 1;

  int ret = 0;

  for(int row=0;row<8;row++){
    if(!can_place[row][column]) 
      continue;

    bool can = true;
    for(int i=0;i<column;i++){
      if(placed[i] == row) can = false;
      if(abs(placed[i] - row) == abs(column - i)) can = false;
    }
    
    if(!can) continue;

    placed[column] = row;
    ret += solve(column + 1);
  }

  return ret;
}

int main(){
  fastio;

  for(int i=0;i<8;i++){
    placed[i] = -1;
    for(int j=0;j<8;j++){
      char c;
      cin >> c;
      can_place[i][j] = (c == '.');
    }
  }
    
  
  cout << solve(0) << endl;
  return 0;
}