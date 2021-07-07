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

void couting_sort(vi& p, vi& c){
  int n = sz(p);
  vi cnt(n);
  for(int x:c) cnt[x]++;

  vi posBucket(n);
  posBucket[0] = 0;
  for(int i=1;i<n;i++)
    posBucket[i] = posBucket[i-1]+cnt[i-1];
 
  vi newP(n);
 
  for(int x:p)
    newP[posBucket[c[x]]++] = x;
 
  p = newP;
}


int main(){
  fastio;
  
  string s;
  cin >> s;
  s += "$";

  int n = sz(s);
  vi p(n); //suffix array
  vi c(n); //class

  //base case when k = 0
  iota(all(p), 0);
  sort(all(p),[&](int i,int j){
    return s[i] < s[j];
  });
  for(int i=1;i<n;i++) 
    c[p[i]] = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);

  int k = 0;

  while((1 << k) < n){
    for(int i=0;i<n;i++) //second half is sorted
      p[i] = (p[i] - (1 << k) + n)%n;

    couting_sort(p, c);

    vi new_c(n);
    for(int i=1;i<n;i++){
        pii cur = {c[p[i]],c[(p[i] + (1 << k))%n]};
        pii prev = {c[p[i-1]],c[(p[i-1] + (1 << k))%n]};
        new_c[p[i]] = new_c[p[i-1]] + (cur != prev);
      }
 
      c = new_c;
      k++;
  }

  vi lcp(n);
  k = 0;
  for(int i=0;i<n-1;i++){
    int pi = c[i];
    int j = p[pi-1];
    while(s[i+k] == s[j+k])
      k++;
    lcp[pi] = k;
    k = max(k-1,0);
  }

  for(int i=0;i<n;i++)
    cout << lcp[i] << " " << p[i] << " " << s.substr(p[i]) << endl;;
  

 
  return 0;
}