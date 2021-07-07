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

const int nax = 4e5 + 5;
const int max_log = 20;

int logs[nax];
int table[max_log][nax]; //table[k][i] - min starting at index i with size 2^k
struct SparseTable{
  int n;
  vi a;
  void computeLogs(){
    logs[1] = 0;
    for(int i=2;i<=n;i++)
      logs[i] = logs[i / 2] + 1;
  }

  void build(){
    for(int k=0;k<=logs[n];k++){
      int curLen = 1 << k;
      for(int i=0;i+curLen <= n;i++){
        if(curLen == 1) table[k][i] = a[i];
        else table[k][i] = min(table[k-1][i], table[k-1][i + (curLen / 2)]);
      }
    }
  }

  int get_min(int l,int r){
    int p = logs[r - l + 1];
    int pLen = 1 << p;
    return min(table[p][l], table[p][r - pLen + 1]);
  }

  SparseTable(vi& a):a(a){
    n = sz(a);
    computeLogs();
    build();
  }
};

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
  s += (char)32;
  
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
  
  int m;
  cin >> m;

  vpii substrings(m);

  for(int i=0;i<m;i++){
    cin >> substrings[i].f >> substrings[i].s;
    substrings[i].f--;
    substrings[i].s--;
  }
  
  SparseTable table(lcp);

  sort(all(substrings),[&](auto p1, auto p2){
      int l1 = p1.f, r1 = p1.s, l2 = p2.f, r2 = p2.s;
      int tam1 = r1-l1+1, tam2 = r2-l2+1;
      int pos1 = c[l1];
      int pos2 = c[l2];

      if(l1 == l2) return tam1 < tam2;

      if(pos1 > pos2) swap(pos1, pos2);

      pos1++;

      int LCP = table.get_min(pos1, pos2);

      if(LCP >= tam1 or LCP >= tam2) 
        return (tam1 < tam2) or (tam1 == tam2 and l1 < l2) or
        (tam1 == tam2 and l1 == l2 and r1 < r2); 

      return s[l1 + LCP] < s[l2 + LCP];
  });

  for(auto p:substrings)
    cout << p.f+1 << " " << p.s+1 << endl;

  return 0;
}