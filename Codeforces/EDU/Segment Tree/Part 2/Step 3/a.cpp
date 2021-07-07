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

struct Node{
  ll max_seg, pref, suf, sum;
  Node(ll max_seg=0,ll pref=0, ll suf=0, ll sum=0): max_seg(max_seg),pref(pref), suf(suf),sum(sum){}
};

struct SegTree{
  vector <Node> st;
  vi lazy;
  int sz;

  void build(int n){
    sz = n;
    st.assign(4*n, Node());
    lazy.assign(4*n, INT_MAX);
  }

  void propagate(int pos,int l,int r){
    int v = lazy[pos];

    if(v == INT_MAX)
      return;
    
    int m = (l+r)/2;
    ll sumLeft = 1LL*(m-l+1)*v;
    ll sumRight = 1LL*(r-m)*v;

    if(v > 0){
      st[2*pos+1] = Node(sumLeft,sumLeft,sumLeft,sumLeft);
      st[2*pos+2] = Node(sumRight,sumRight,sumRight,sumRight);
    } 
    else{
        st[2*pos+1] = Node(v,v,v,sumLeft);
        st[2*pos+2] = Node(v,v,v,sumRight);
    }
    
    lazy[2*pos+1] = lazy[2*pos+2] = v;
    lazy[pos] = INT_MAX;
  }

  Node get_cur(Node left,Node right){
    Node cur;

    cur.sum = left.sum + right.sum;
    cur.pref = max(left.pref, left.sum + right.pref);
    cur.suf = max(right.suf, right.sum + left.suf);
    cur.max_seg = max({left.max_seg, right.max_seg, left.suf + right.pref});

    return cur;
  }

  void assign(int l,int r,int pos,int ql,int qr,int v){
    if(qr < l || ql > r)
      return;
    
    if(ql <= l && r <= qr){
      lazy[pos] = v;
      ll sum = 1LL*(r-l+1)*v;
      if(v > 0)
        st[pos] = Node(sum,sum,sum,sum);
      else
        st[pos] = Node(v,v,v,sum);
      return;
    }

    propagate(pos,l,r);

    int m = (l+r)/2;
    
    assign(l,m,2*pos+1,ql,qr,v);
    assign(m+1,r,2*pos+2,ql,qr,v);

    Node left = st[2*pos+1];
    Node right = st[2*pos+2];

    st[pos] = get_cur(left,right);
  }

  void assign(int ql, int qr,int v){
    assign(0,sz-1,0,ql,qr,v);
  }

  ll max_segment(){
    return max(0LL,st[0].max_seg);
  }
};

int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  SegTree st;
  st.build(n);

  while(m--){
    int l,r,v;
    cin >> l >> r >> v;
    r--;
    st.assign(l,r,v);
    cout << st.max_segment() << endl;
  }

  return 0;
}