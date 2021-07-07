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

//1 - black;
//0 - white;

const int nax = 2000020;

struct Node{
  int black;
  int seg_black;
  bool start_black;
  bool end_black;
  Node(int black=0,int seg_black=0,bool start_black=false, bool end_black=false):
  black(black), seg_black(seg_black), start_black(start_black), end_black(end_black){}
};

struct Segtree{
  vector <Node> st;
  vi lazy;
  Segtree(){
    st.assign(4*nax, Node());
    lazy.assign(4*nax, -1);
  }
  void propagate(int pos,int l, int r){
    if(lazy[pos] == -1) return;

    if(lazy[pos]) st[pos] = Node(r-l+1, 1, true, true);
    else st[pos] = Node();

    if(l != r){
      lazy[2*pos+1] = lazy[pos];
      lazy[2*pos+2] = lazy[pos];
    }

    lazy[pos] = -1;
  }

  void merge(int pos,int l, int r){
    Node left = st[2*pos+1];
    Node right = st[2*pos+2];
    Node node;
    node.black = left.black + right.black;
    node.seg_black = left.seg_black + right.seg_black - (left.end_black and right.start_black);
    node.start_black = left.start_black;
    node.end_black = right.end_black;
    st[pos] = node;
  }

  void update(int v,int ql,int qr,int pos=0,int l=0, int r=nax-1){
    propagate(pos, l, r);
    if(ql > r or qr < l) return;
    if(ql <= l and r <= qr){
      lazy[pos] = v;
      propagate(pos, l, r);
      return;
    }
    int m = (l+r)/2;
    update(v, ql, qr, 2*pos+1, l, m);
    update(v, ql, qr, 2*pos+2, m+1, r);
    merge(pos, l, r);
  }

  pii query(){
    return {st[0].seg_black, st[0].black};
  }
};

int main(){
  fastio;
  int n;
  cin >> n;
  Segtree st;

  while(n--){
    char c;
    int x, L;
    cin >> c >> x >> L;
    x += 500000;
    int l = x, r = x + L - 1;
    int v = (c == 'B');
    st.update(v, l, r);
    pii ans = st.query();
    cout << ans.f << " " << ans.s << endl;
  }
  
  return 0;
}