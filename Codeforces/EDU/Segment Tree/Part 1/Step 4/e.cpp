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

const int INF = 1e9 + 7;

struct SegTree{
  vi st;
  int sz;
  void build(int n){
    sz = n;
    st.assign(4*n,INF);
  }

  void update(int l,int r,int pos,int i,int v){
    if(i < l || i > r)
      return;
    if(l == r){
      st[pos] = v;
      return;
    }

    int m = (l+r)/2;
    
    update(l,m,2*pos+1,i,v);
    update(m+1,r,2*pos+2,i,v);

    st[pos] = min(st[2*pos+1],st[2*pos+2]);
  }
  void update(int i,int v){
    update(0,sz-1,0,i,v);
  }

  int query(int l,int r, int pos,int ql,int qr,int p){
    if(qr < l || ql > r || st[pos] > p)
      return 0;
    
    if(l == r){
      st[pos] = INF;
      return 1;
    }

    int m = (l+r)/2;

    int left = query(l,m,2*pos+1,ql,qr,p);
    int right = query(m+1,r,2*pos+2,ql,qr,p);

    return left + right;
  }
  
  int query(int ql,int qr,int p){
    return query(0,sz-1,0,ql,qr,p);
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
      int i,h;
      cin >> i >> h;
      st.update(i,h);
    }else{
      int l,r,p;
      cin >> l >> r >> p;
      cout << st.query(l,r-1,p) << endl;
    }
  }

  return 0;
}