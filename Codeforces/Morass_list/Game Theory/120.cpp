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


int main(){
  fastio;

  ifstream in ("input.txt");
	streambuf *cinbuf = cin.rdbuf ();
	cin.rdbuf (in.rdbuf ());
 
	ofstream out ("output.txt");
	streambuf *coutbuf = cout.rdbuf ();
	cout.rdbuf (out.rdbuf ());

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << (n+1)%2 << endl;
  }
  

  cin.rdbuf (cinbuf);
	cout.rdbuf (coutbuf);


  return 0;
}