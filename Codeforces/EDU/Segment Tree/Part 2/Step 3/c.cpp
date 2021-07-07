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


struct SegTree{
  vi st;
  vi lazy;
  int sz;

  void build(int n){
    sz = n;
    st.assign(4*n, 0);
    lazy.assign(4*n, 0);
  }

  void propagate(int pos){
    lazy[2*pos+1] += lazy[pos];
    lazy[2*pos+2] += lazy[pos];
    st[2*pos+1] += lazy[pos];
    st[2*pos+2] += lazy[pos];
    lazy[pos] = 0;
  }

  void add(int l,int r,int pos,int ql,int qr,int v){
    if(qr < l || ql > r)
      return;
    
    if(ql <= l && r <= qr){
      lazy[pos] += v;
      st[pos] += v;
      return;
    }

    propagate(pos);

    int m = (l+r)/2;

    add(l,m,2*pos+1,ql,qr,v);
    add(m+1,r,2*pos+2,ql,qr,v);

    st[pos] = max(st[2*pos+1],st[2*pos+2]);
  }

  void add(int ql,int qr,int v){
    add(0,sz-1,0,ql,qr,v);
  }

  int first_above(int l,int r,int pos, int x,int i){
    if(i > r)
      return -1;

    if(l == r)
      return l;
    
    propagate(pos);
    
    int left_max = st[2*pos+1];

    int m = (l+r)/2;
    
    int left_ret = -1;

    if(left_max >= x)
      left_ret = first_above(l,m,2*pos+1,x,i);
    
    if(left_ret == -1){
      int right_max = st[2*pos+2];
      int right_ret = -1;

      if(right_max >= x)
        right_ret = first_above(m+1,r,2*pos+2,x,i);
      return right_ret;
    }

    return left_ret;
  }

  int first_above(int x,int i){
    return first_above(0,sz-1,0,x,i);
  }
  
};

int main(){
  fastio;

  int n,m;
  cin >> n >> m;

  SegTree st;
  st.build(n);

  while(m--){
    int type;
    cin >> type;

    if(type == 1){
      int l,r,v;
      cin >> l >> r >> v;
      r--;
      st.add(l,r,v);
    }else{
      int x,l;
      cin >> x >> l;
      cout << st.first_above(x,l) << endl;
    }
  }

  return 0;
}