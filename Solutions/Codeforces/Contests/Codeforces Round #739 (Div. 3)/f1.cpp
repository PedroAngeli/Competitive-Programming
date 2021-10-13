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

int n, K;
int dp[15][1030][2];
string S;

int solve(int i,int j, int k){
  if(__builtin_popcount(j) > K)
    return 0;
  if(i == S.size())
    return 1;
  int& state = dp[i][j][k];
  if(state != -1)
    return state;
  state = 0;
  if(k == 0)
    for(int dig=S[i]-'0';dig<=9;dig++)
      state = (state or solve(i+1, j | (1 << dig), dig > (S[i]-'0')));
  else
    for(int dig=0;dig<=9;dig++)
      state = (state or solve(i+1, j | (1 << dig), k));
  return state;
}

void find_ans(int i, int j, int k){
  if(i == S.size())
    return;

  if(k == 0){
    for(int dig=S[i]-'0';dig<=9;dig++)
      if(solve(i+1, j | (1 << dig), dig > (S[i]-'0'))){
        cout << dig;
        find_ans(i+1, j | (1 << dig), dig > (S[i]-'0'));
        return;
      }
  }

  for(int dig=0;dig<=9;dig++)
    if(solve(i+1, j | (1 << dig), k)){
      cout << dig;
      find_ans(i+1, j | (1 << dig), k);
      return;
    }
}

int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    cin >> n >> K;
    S = to_string(n);
    memset(dp, -1, sizeof dp);
    solve(0, 0, 0);
    find_ans(0, 0, 0);
    cout << endl;
  }
  
  return 0;
}