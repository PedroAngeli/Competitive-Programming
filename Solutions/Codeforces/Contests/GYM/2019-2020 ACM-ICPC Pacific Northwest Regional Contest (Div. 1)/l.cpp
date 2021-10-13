#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

string a,ans,cur;

void solve(int i){
  if(i < 0){
    ans = min(ans,cur);
    return;
  }
  char mx = '9';

  if(i < sz(a)/2)
    mx = '0';

  for(cur[i] = '0';cur[i] <=mx;cur[i]++){
      int dig = 0;
      int l = i;
      int r = sz(a)-1;
      while(l < sz(a)){
        dig += (cur[l]-'0')*(cur[r]-'0');
        l++,r--;
      }
      char c = dig%10 + '0';
      if(c == a[i])
        solve(i-1);
    }
  
}

int main(){
  fastio;

  cin >> a;

  ans.assign(sz(a),'z');
  cur.assign(sz(a),'0');
  solve(sz(a)-1);

  if(ans[0] == 'z'){
    cout << -1 << endl;
    return 0;
  }
  int i;

  for(i=0;i<sz(ans) && (ans[i] == '0');i++){}
  
  ans = ans.substr(i);
  cout << ans << endl;
  return 0;
}