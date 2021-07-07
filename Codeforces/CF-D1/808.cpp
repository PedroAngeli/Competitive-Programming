#include <bits/stdc++.h>
 
using namespace std;
 
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


int main(){
  fastio;

  int n;
  cin >> n;
  vll a(n);
  map <ll,int> cnt;
  ll sum = 0;

  for(int i=0;i<n;i++)
    cin >> a[i],sum += a[i];

  if(sum % 2 == 1){
    cout << "NO" << endl;
    return 0;
  }

  ll pref = 0;

  for(int i=0;i<n;i++){
    pref += a[i];
    cnt[a[i]]++;
    if(cnt[pref-(sum/2)] != 0){
      cout << "YES" << endl;
      return 0;
    }
  }

  cnt.clear();

  ll suf = 0;

  for(int i=n-1;i>=0;i--){
    suf += a[i];
    cnt[a[i]]++;
     if(cnt[suf-(sum/2)] != 0){
      cout << "YES" << endl;
      return 0;
    }
  }


  cout << "NO" << endl;

  return 0;
}