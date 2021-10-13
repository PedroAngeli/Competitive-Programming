#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 

int main(){
  fastio;

  int n,k;
  cin >> n >> k;

  vi x(n);

  for(int i=0;i<n;i++)
    cin >> x[i];

  ordered_set conj;

  for(int i=0;i<k;i++)
    conj.insert({x[i],i});

  for(int i=k;i<n;i++){
    auto p = *conj.find_by_order((k-1)/2);
    cout << p.f << " ";
    conj.erase({x[i-k],i-k});
    conj.insert({x[i],i});
  }

  auto p = *conj.find_by_order((k-1)/2);
    cout << p.f << " ";
    cout << endl;
  return 0;
}