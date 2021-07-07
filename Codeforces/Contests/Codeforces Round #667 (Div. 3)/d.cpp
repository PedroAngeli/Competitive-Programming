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


int get_sum(string& a){
  int sum = 0;
  
  for(char c:a)
    sum += (c-'0');

  return sum;
}
int main(){
  fastio;

  int t = 1;
  cin >> t;

  while(t--){
    ll n,s;
    cin >> n >> s;

    string a = to_string(n);
    int sum = get_sum(a);
    ll N = n;

    while(sum > s){
      int i = sz(a) - 1;
      ll add = 10;
      while(i >=0 && a[i] == '0')
        i--, add*=10;
      a[i] = '0';
      N = stoll(a) + add;
      a = to_string(N);
      sum = get_sum(a);
    }
    ll val = stoll(a);
    cout << val-n << endl;
  }

  return 0;
}