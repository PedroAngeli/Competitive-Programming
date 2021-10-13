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

int n;
string s;
int dp[105][3];

int solve(int i,int j){
  if(i == n)
    return 0;
  
  int& state = dp[i][j];
  if(state != -1)
    return state;
  
  if(s[i] == 'B')
    return state = (j == 0) + solve(i+1, 0);
  if(s[i] == 'R')
    return state = (j == 1) + solve(i+1, 1);

  return state = min((j == 0) + solve(i+1, 0), (j == 1) + solve(i+1, 1));
}
void find_ans(int i, int j){
  if(i == n)
    return;
  int& state = dp[i][j];
  if(s[i] == 'B')
    cout << "B", find_ans(i+1, 0);
  else if(s[i] == 'R')
    cout << "R", find_ans(i+1, 1);
  else if(state == (j == 0) + solve(i+1, 0))
    cout << "B", find_ans(i+1, 0);
  else
    cout << "R", find_ans(i+1, 1);
}
int main(){
  fastio;

  int t;
  cin >>t;
  while(t--){
    cin >> n;
    cin >> s;
    memset(dp, -1, sizeof dp);
    solve(0, 2);
    find_ans(0, 2);
    cout << endl;
  }
  return 0;
}