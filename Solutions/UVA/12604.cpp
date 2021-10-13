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

vi pi(string pattern){ //Computa a função do prefixo do pattern.
    vi p(sz(pattern), 0);
    for(int i=1,j=0;i<sz(pattern);i++){
      while(j > 0 and pattern[i] != pattern[j]) j = p[j-1];
      if(pattern[i] == pattern[j]) j++;
      p[i] = j;
    }
    return p;
  }

  int matching(string& text, string& pattern){ //recebe o texto e o padrão e retorna os indices dos matchings.
    vi p = pi(pattern + '$');
    int cnt = 0;
    for(int i=0,j=0;i<sz(text);i++){
      while(j > 0 and text[i] != pattern[j]) j = p[j-1];
      if(text[i] == pattern[j]) j++;
      if(j == sz(pattern)) cnt++;
    }

    return cnt;
  }


map <char,int> pos;

int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    string A, W, S;
    cin >> A >> W >> S;
    pos.clear();
    for(int i=0;i<sz(A);i++) pos[A[i]] = i;
    vi ans;

    for(int i=0;i<sz(A);i++){
      int cmp = sz(A) - i;
      string new_S = S;

      for(char& c:new_S){
        int p = pos[c];
        p += cmp;
        p %= sz(A);
        c = A[p];
      }

      if(matching(new_S, W) == 1) ans.pb(i);
    }

    if(sz(ans) == 0) cout << "no solution" << endl;
    else if(sz(ans) == 1) cout << "unique: " << ans[0] << endl;
    else{
      cout << "ambiguous:";
      for(int x:ans)
        cout << " " << x;
      cout << endl;
    }
  }
  
  return 0;
}