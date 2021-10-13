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

void print(string& a){
  cout << " is a misspelling of " << a;
}

bool type1(string a, string b){
  if(sz(a) > sz(b)) swap(a,b);

  int i = 0;
  int j = 0;

  while(i < sz(a) && j < sz(b)){
    if(b[j] == a[i]) i++;
    j++;
  }

  return (i == sz(a));
}

bool one_letter(string a,string b){
  int cnt = 0;
  
  for(int i=0;i<sz(a);i++) cnt += (a[i] != b[i]);

  return (cnt == 1);
}

bool adj_letter(string a,string b){
  vi pos;  
  for(int i=0;i<sz(a);i++)
    if(a[i] != b[i]) pos.pb(i);

  if(sz(pos) != 2) return false;
  sort(all(a));
  sort(all(b));

  return (pos[0] + 1 == pos[1]) && (a == b);
}

bool exists(vs& dic, string& a){
  for(auto s1 : dic) if(s1 == a) return true;

  return false;
}

int main(){
  fastio;

  int n;
  cin >> n;
  vs dic(n);
  for(int i=0;i<n;i++) cin >> dic[i];

  int q;
  cin >> q;
  while(q--){
    string S;
    cin >> S;
    cout << S;
    bool can = false;

    if(exists(dic, S)) cout << " is correct", can = true;
    else{
      for(string a : dic){
          if(abs(sz(a) - sz(S)) == 1){
            if(type1(S, a)) print(a), can = true;
          }else if(sz(a) == sz(S)){
             if(one_letter(S, a)) print(a), can = true;
             else if(adj_letter(S,a)) print(a), can = true;
          }
        if(can) break;
      }
    }

    if(!can) cout << " is unknown";
    cout << endl;
  }
  return 0;
}