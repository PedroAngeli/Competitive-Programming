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

int n,q;

struct Segtree{
  vector <vi> st;
  vi lazy;
  vi freq_ans;
  int new_freq[9];

  void build(int l,int r,int pos){
    if(l == r){
      st[pos][1] = 1;
      return;
    }
    int m = (l+r)/2;
    build(l,m,2*pos+1);
    build(m+1,r,2*pos+2);
    for(int i=0;i<=8;i++)
       st[pos][i] = st[2*pos+1][i] + st[2*pos+2][i];
  }

  Segtree(){
    st.assign(4*n, vi(9, 0));
    lazy.assign(4*n, 0);
    build(0, n-1, 0);
  }
  
  int most_freq(){
    int mx = 0;
    int nota = 0;
    for(int i=8;i>=0;i--){
      if(freq_ans[i] > mx){
        mx = freq_ans[i];
        nota = i;
      }
    }
    return nota;
  }

  void propagate(int pos, int l,int r){
    if(lazy[pos] == 0) return;
    if(l != r){
      lazy[2*pos+1] += lazy[pos];
      lazy[2*pos+2] += lazy[pos];
    }
    
    for(int i=0;i<=8;i++){
      int ni = i + lazy[pos];
      new_freq[ni%9] = st[pos][i];
    } 
    for(int i=0;i<=8;i++){
      st[pos][i] = new_freq[i];
    }
    lazy[pos] = 0;
  }

  void update(int l,int r,int pos,int ql, int qr, int val){
    propagate(pos, l, r);
    if(ql > r or qr < l) return;
    if(ql <= l and r <= qr){
      lazy[pos] += val;
      propagate(pos, l, r);
      return;
    }
    int m = (l+r)/2;
    update(l, m, 2*pos+1, ql, qr, val);
    update(m+1, r, 2*pos+2, ql, qr, val);
    for(int i=0;i<=8;i++)
       st[pos][i] = st[2*pos+1][i] + st[2*pos+2][i];
  }

  void update(int ql,int qr, int val){
    update(0, n-1, 0, ql, qr, val);
  }

  void query(int l,int r,int pos,int ql,int qr){
    propagate(pos, l, r);
    if(ql > r or qr < l) return;
    if(ql <= l and r <= qr){
      for(int i=0;i<=8;i++) freq_ans[i] += st[pos][i];
      return;
    } 
    int m = (l+r)/2;
    query(l, m, 2*pos+1, ql, qr);
    query(m+1, r, 2*pos+2, ql, qr);
  }

  int query(int ql,int qr){
    freq_ans.assign(9, 0);
    query(0, n-1, 0, ql, qr);
    return most_freq();
  }
  
};

int main(){
  fastio;

  cin >> n >> q;

  Segtree st;

  while(q--){
    int l, r;
    cin >> l >> r;
    int most_freq = st.query(l, r);
    st.update(l, r, most_freq);
  }

  for(int i=0;i<n;i++)
    cout << st.query(i,i) << endl;

  return 0;
}