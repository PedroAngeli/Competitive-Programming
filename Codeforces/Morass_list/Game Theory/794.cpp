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

  string s1,s2;
  cin >> s1 >> s2;
  sort(all(s1));
  sort(all(s2));
  reverse(all(s2));

  deque <char> a,b;
  int n = sz(s1);
  for(int i=0;i<(n+1)/2;i++)
    a.pb(s1[i]);
  for(int i=0;i<(n/2);i++)
    b.pb(s2[i]);
  
  string op1 = "", op2 = "";

  for(int i=0;i<n;i++){
    if(i%2){
      if(b[0] > a[0]){
        op1 += b[0];
        b.pop_front();
      }else{
        op2 += b.back();
        b.pop_back();
      }
    }else{
      if(a[0] < b[0]){
        op1 += a[0];
        a.pop_front();
      }else{
        op2 += a.back();
        a.pop_back();
      }
    }
  }

  reverse(all(op2));
  
  cout << op1 + op2 << endl;
  
  return 0;
}