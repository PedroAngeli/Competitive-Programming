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

const int max_x = 1000;
const int max_y = 1000;

int ft[max_x+1][max_y+1];

int lsb(int i){
    return i & (-i);
}

void updatey(int x, int y, int val){
    while(y <= max_y){
      ft[x][y] += val;
      y += lsb(y);
    }
}

void update(int x, int y,int val){
    while(x <= max_x){
      updatey(x, y, val);
      x += lsb(x);
    }
}

int sum_range_y(int x,int y){
  int ret = 0;
  while(y){
    ret += ft[x][y];
    y -= lsb(y);
  }
  return ret;
}

int sum_range(int x,int y){
  int ret = 0;
  while(x){
    ret += sum_range_y(x, y);
    x -= lsb(x);
  }
  return ret;
}

int query(int x1, int y1,int x2,int y2){
  return sum_range(x2, y2) - sum_range(x2, y1 - 1) - 
  sum_range(x1 - 1,y2) + sum_range(x1-1,y1-1);
}

int get(int x, int y){
  return query(x,y,x,y);
}

int main(){
  fastio;

  int n, q;
  cin >> n >> q;

  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      char c;
      cin >> c;
      if(c == '*') update(i, j, 1);
    }

  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int x,y;
      cin >> x >> y;
      int val = get(x, y);
      if(val) val *= -1;
      else val++;
      update(x, y, val);
    }else{
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if(x1 > x2) swap(x1, x2);
      if(y1 > y2) swap(y1, y2);
      cout << query(x1, y1, x2, y2) << endl;
    }
  }
  return 0;
}