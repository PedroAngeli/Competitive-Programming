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
    lazy.assign(4*n, false);
  }

  void propagate(int pos,int l,int r){
    if(lazy[pos] % 2 == 0)
      return;

    int m = (l+r)/2;
    
    lazy[2*pos+1]++; 
    lazy[2*pos+2]++;
    lazy[pos] = 0;
    st[2*pos+1] = (m-l+1) - st[2*pos+1];
    st[2*pos+2] = (r-m) - st[2*pos+2];
  }

  void invert(int l,int r,int pos,int ql,int qr){
    if(qr < l || ql > r)
      return;

    if(ql <= l && r <= qr){
      lazy[pos]++;
      st[pos] = (r-l+1) - st[pos];
      return;
    }

    propagate(pos,l,r);

    int m = (l+r)/2;

    invert(l,m,2*pos+1,ql,qr);
    invert(m+1,r,2*pos+2,ql,qr);

    st[pos] = st[2*pos+1] + st[2*pos+2];
  }

  void invert(int ql,int qr){
    invert(0,sz-1,0,ql,qr);
  }

  int kth_one(int l,int r,int pos,int i){
    if(l == r)
      return l;
    
    propagate(pos,l,r);

    int m = (l+r)/2;

    int left = st[2*pos+1];

    if(left > i)
      return kth_one(l,m,2*pos+1,i);
    else
      return kth_one(m+1,r,2*pos+2,i-left);
  }

  int kth_one(int i){
    return kth_one(0,sz-1,0,i);
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
      int l,r;
      cin >> l >> r;
      r--;
      st.invert(l,r);
    }else{
      int k;
      cin >> k;
      cout << st.kth_one(k) << endl;
    }
  }

  return 0;
}