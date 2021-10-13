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

ll pascal[51][51];

void generates_pascal(){
    for(int i=0;i<=50;i++)
      for(int j=0;j<=i;j++){
        if(j == 0 || j == i) pascal[i][j] = 1;
        else pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
      }
}
int main(){
  fastio;

  generates_pascal();

  int t;
  cin >> t;

  for(int tt=1;tt<=t;tt++){
    string line;
    cin >> line;
    int p1 = line.find("+", 1);
    string n1 = line.substr(1, p1-1);

    int p2 = line.find(")", p1+1);
    string n2 = line.substr(p1+1, p2-p1-1);

    int K = stoi(line.substr(p2 + 2));
    
    cout << "Case " << tt << ": ";
    for(int i=0;i<=K;i++){
      bool one = false;

      if(pascal[K][i] > 1) cout << pascal[K][i] << "*";
      if(K-i > 0){
        one = true;
        cout << n1;
        if(K-i > 1) cout << "^" << K-i;
      }

      if(i > 0){
        if(one) cout << "*";
        cout << n2;
        if(i > 1) cout << "^" << i;
      }

      if(i < K) cout << "+";
    }
    cout << endl;
  } 
  return 0;
}