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


int main(){
  fastio;

  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    string a;
    cin >> a;
    bool odd_in_odd = false;
    bool even_in_even = false;

    for(int i=1;i<=n;i++){
      int dig = a[i-1] - '0';
      if(i%2 == 1 && dig%2 == 1)
        odd_in_odd = true;
      else if(i%2 == 0 && dig%2 == 0)
        even_in_even = true;
    }
    if(n%2 == 0){
      if(even_in_even)
        cout << 2 << endl;
      else
        cout << 1 << endl;
    }else{
      if(odd_in_odd)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }    
  }

  return 0;
}