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

  int n;
  cin >> n;
  bool oc = false;
  int row = 0;

  while(n--){
    int d1,d2;
    cin >> d1 >> d2;
    if(d1 == d2)
      row++;
    else
      row = 0;
    if(row == 3)
      oc = true;
  }

  if(oc)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}