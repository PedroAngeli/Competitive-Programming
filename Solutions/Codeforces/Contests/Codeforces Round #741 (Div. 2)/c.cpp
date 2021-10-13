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

  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int pz = -1;
    for(int i=0;i<n;i++)
      if(s[i] == '0'){
        pz = i;
        break;
      }
    
    if(pz == -1){
      if(n == 2){
        cout << "1 1 2 2" << endl;
        continue;
      }
      cout << 1 << " " << n/2 + 1 << " " << 2 << " " << n/2 + 2 << endl;
      continue;
    }

    if(pz >= n/2){
      cout << 1 << " " << pz+1 << " " << 1 << " " << pz << endl;
      continue; 
    }

    cout << pz+1 << " " << n << " " << pz+2 << " " << n << endl;
  }
  
  return 0;
}