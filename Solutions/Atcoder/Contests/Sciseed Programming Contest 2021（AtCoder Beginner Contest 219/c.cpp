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


int main(){
  fastio;

  string order;
  cin >> order;

  vector <int> pos(26, 0);

  for(int i=0;i<order.size();i++)
    pos[order[i] - 'a'] = i;

  int n;
  cin >> n;
  vector <string> S(n);

  for(int i=0;i<n;i++)
    cin >> S[i];
  
  sort(all(S),[&](auto s1, auto s2){
    int i = 0, j = 0;
    while(i < s1.size() and j < s2.size()){
      if(s1[i] != s2[j])
        return pos[s1[i]-'a'] < pos[s2[i]-'a'];
      i++, j++;
    }
    return i == s1.size();
  });

  for(auto s:S)
    cout << s << endl;

  return 0;
}