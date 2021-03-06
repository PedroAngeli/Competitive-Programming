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

vi a;
int n;

int main(){
  fastio;

  cin >> n;
  a.resize(n + 1);

  for(int i=1;i<=n;i++)
    cin >> a[i];

  vi b(n+2);
  b[1] = 0;

  for(int i=2;i<=n+1;i++)
    b[i] = a[i-1] - b[i-1];
  
  int mnEven = INT_MAX;
  int mnOdd = INT_MAX;
  bool can = true;

  for(int i=1;i<=n+1;i++){
    if(i%2 == 0 && b[i] < 0) can = false;
    if(i%2)  mnOdd = min(mnOdd, b[i]);
    else mnEven = min(mnEven, b[i]);
  }

   if(!can){
    cout << 0 << endl;
    return 0;
  }

  cout << max(0,mnEven - abs(mnOdd) + 1) << endl;

  return 0;
}