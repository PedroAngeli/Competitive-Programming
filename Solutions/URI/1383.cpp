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

  int n;

  cin >> n;
  
  for(int instancia=0;instancia<n;instancia++){
    cout << "Instancia " << instancia+1 << endl;
      int mat[9][9];
      set <int> col[9];
      set <int> line[9];

      for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
          cin >> mat[i][j];
          if(mat[i][j] > 9) continue;
          col[j].insert(mat[i][j]);
          line[i].insert(mat[i][j]);
        }

        bool can = true;

        for(int i=0;i<9;i+=3)
          for(int j=0;j<9;j+=3){
            set <int> test;
            for(int l=i;l<i+3;l++)  
              for(int m=j;m<j+3;m++)
                test.insert(mat[l][m]);

            if(test.size() < 9) 
              can = false;
          }
        
        for(int i=0;i<9;i++)
          if(col[i].size() < 9 or line[i].size() < 9)
            can = false;

        if(can)
          cout << "SIM" << endl;
        else 
          cout << "NAO" << endl;

        cout << endl;
  }
    
      
  

  
  return 0;
}