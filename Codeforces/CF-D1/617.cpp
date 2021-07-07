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

vpii p;

bool one(){
  return (p[0].f == p[1].f && p[0].f == p[2].f) || (p[0].s == p[1].s && p[0].s == p[2].s);
}

bool two(){
  if(p[0].f == p[1].f)
    return !(p[2].s > min(p[0].s, p[1].s) && p[2].s < max(p[0].s, p[1].s));
  if(p[0].f == p[2].f)
    return !(p[1].s > min(p[0].s, p[2].s) && p[1].s < max(p[0].s, p[2].s));
  if(p[1].f == p[2].f)
    return !(p[0].s > min(p[1].s, p[2].s) && p[0].s < max(p[1].s, p[2].s));
  if(p[0].s == p[1].s)
    return !(p[2].f > min(p[0].f, p[1].f) && p[2].f < max(p[0].f, p[1].f));
  if(p[0].s == p[2].s)
    return !(p[1].f > min(p[0].f, p[2].f) && p[1].f < max(p[0].f, p[2].f));
  if(p[1].s == p[2].s)
    return !(p[0].f > min(p[1].f, p[2].f) && p[0].f < max(p[1].f, p[2].f));
  return false;
}

int main(){
  fastio;
  p.resize(3);
  for(int i=0;i<3;i++)
    cin >> p[i].f >> p[i].s;


  if(one())
    cout << 1 << endl;
  else if(two())
    cout << 2 << endl;
  else
    cout << 3 << endl;

  return 0;
}