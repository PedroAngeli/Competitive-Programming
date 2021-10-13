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
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
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

struct Range{
  int x, y, id;
};

int main(){
  fastio;

  int n;
  cin >> n;

  vector <Range> a(n);

  for(int i=0;i<n;i++)
    cin >> a[i].x >> a[i].y, a[i].id = i;

  vi first_line(n), second_line(n);

  sort(all(a),[&](auto i, auto j){
    return (i.x < j.x) or 
    (i.x == j.x and i.y > j.y);
  });

  ordered_multiset Y;

  for(int i=n-1;i>=0;i--){
    int lte = Y.order_of_key(a[i].y + 1);
    first_line[a[i].id] = lte > 0;
    Y.insert(a[i].y);
  }

  sort(all(a),[&](auto i, auto j){
    return (i.y < j.y) or 
    (i.y == j.y and i.x > j.x);
  });

  ordered_multiset X;
  for(int i=n-1;i>=0;i--){
    int lte = X.order_of_key(a[i].x + 1);
    second_line[a[i].id] = lte > 0;
    X.insert(a[i].x);
  }

  for(int i=0;i<n;i++)
    cout << first_line[i] << " ";
  cout << endl;

  for(int i=0;i<n;i++)
    cout << second_line[i] << " ";
  cout << endl;  
  return 0;
}