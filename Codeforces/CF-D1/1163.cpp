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

int n, ms, mt;
int dp[1001][55][55];
vector <vi> nxt_s, nxt_t;
string code;

namespace KMP{
  vector <int> pi(string pattern){ //Computa a função do prefixo do pattern.
    vector <int> p(sz(pattern), 0);
    for(int i=1,j=0;i<sz(pattern);i++){
      while(j > 0 and pattern[i] != pattern[j]) j = p[j-1];
      if(pattern[i] == pattern[j]) j++;
      p[i] = j;
    }
    return p;
  }
};

struct autKMP{
  vector <vector <int> > nxt; //nxt[c][i] -> transição da leitura da letra c no estado i
  autKMP(string& pattern): nxt(26, vector <int> (sz(pattern) + 1)){
    vector <int> p = KMP :: pi(pattern);
    nxt[pattern[0] - 'a'][0] = 1;
    for(char c=0;c<26;c++){
      for(int i=1;i<=sz(pattern);i++)
        nxt[c][i] = (c == pattern[i]-'a') ? i + 1 : nxt[c][p[i-1]];
    }
  }
};

int solve(int i,int j, int k){
  if(i == n) return (j == ms) - (k == mt);
  
  int& state = dp[i][j][k];
  if(state != INT_MIN) return state;

  for(char c='a';c<='z';c++){
    if(code[i] == '*' || code[i] == c)
      state = max(state, (j == ms) - (k == mt) + solve(i+1, nxt_s[c - 'a'][j], nxt_t[c-'a'][k]));
  }

  return state;
}

int main(){
  fastio;

  string s, t;
  cin >> code >> s >> t;
  n = sz(code), ms = sz(s), mt = sz(t);
  autKMP as(s); nxt_s = as.nxt;
  autKMP at(t); nxt_t = at.nxt;
  for(int i=0;i<1000;i++)
    for(int j=0;j<=50;j++)
      for(int k=0;k<=50;k++)
        dp[i][j][k] = INT_MIN;
  cout << solve(0,0,0) << endl;
  return 0;
}