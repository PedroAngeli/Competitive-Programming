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


int main(){
  fastio;

  vi x(3), y(3);

  int area = 0;
  for(int i=0;i<3;i++){
    cin >> x[i] >> y[i];
    area += x[i]*y[i];
  }

  int n = sqrt(area);
  if(n*n != area){
    cout << -1 << endl;
    return 0;
  }

  for(int mask=0;mask<8;mask++){
    vi perm(3);
    iota(all(perm), 0);
    do{
      vs grid(n, string(n, '-'));
      bool can = true;
      for(int k:perm){
        if(mask & (1 << k)) swap(x[k], y[k]);

          for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
              if(grid[i][j] == '-'){
                if(i + x[k] > n or j + y[k] > n){
                  can = false;
                  i = n;
                  break;
                }

                for(int l=i;l<i+x[k];l++)
                  for(int m=j;m<j+y[k];m++)
                    if(grid[l][m] == '-')
                      grid[l][m] = 'A' + k;
                    else{
                      can = false;
                      break;
                    }
                i = n;
                break;
              }      
        if(mask & (1 << k)) swap(x[k], y[k]);
        if(can == false) break;
      }

      if(can){
        cout << n << endl;
        for(string s:grid)
          cout << s << endl;
        return 0;
      }
    }while(next_permutation(all(perm))); 
  }

  cout << -1 << endl;
  
  return 0;
}